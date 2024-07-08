const { availableMemory } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

const input = [];
rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	solution(input);
});

const DIR_Y = [-1, 1, 0, 0];
const DIR_X = [0, 0, 1, -1];

const RAINBOW_BLOCK = 0;
const BLACK_BLOCK = -1;
const EMPTY = -2;

function solution(input) {
	const [N, M] = input[0].split(' ').map(Number);
	let map = [];
	for (let i = 1; i <= N; i++) {
		map.push(input[i].split(' ').map(Number));
	}

	const selectGroup = function() {
		const visited = new Array(N).fill(null).map(() => Array(N).fill(false));

		const BFS = function(startY, startX) {
			const group = {
				standard: [N, N],
				blocks: [],
				rainbow: 0
			}
			const queue = [ [startY, startX ] ];
			const tempVisited = new Array(N).fill(null).map(() => Array(N).fill(false));
			tempVisited[startY][startX] = true;
			visited[startY][startX] = true;
			const blockColor = map[startY][startX];

			while (queue.length !== 0) {
				const [cy, cx] = queue.shift();
				if (map[cy][cx] === RAINBOW_BLOCK) {
					group.rainbow++;
				} else if (cy < group.standard[0] || (cy === group.standard[0] && cx < group.standard[1])) {
					group.standard = [cy, cx];
				}
				group.blocks.push([cy, cx]);

				for (let i = 0; i < 4; i++) {
					const ny = cy + DIR_Y[i];
					const nx = cx + DIR_X[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (tempVisited[ny][nx]) continue;
					if (map[ny][nx] !== blockColor && map[ny][nx] !== RAINBOW_BLOCK) continue;
					tempVisited[ny][nx] = true;
					visited[ny][nx] = true;
					queue.push([ny, nx]);
				}
			}
			return group;
		}

		let resultGroup = {
			standard: [-1, -1],
			blocks: [],
			rainbow: 0
		}
		for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (map[i][j] < 1) continue;
				if (visited[i][j]) continue;
				const group = BFS(i, j);
				if (group.blocks.length < resultGroup.blocks.length) continue;
				if (group.blocks.length > resultGroup.blocks.length) {
					resultGroup = group;
					continue;
				}
				if (group.rainbow < resultGroup.rainbow) continue;
				if (group.rainbow > resultGroup.rainbow) {
					resultGroup = group;
					continue;
				}
				if (group.standard[0] < resultGroup.standard[0]) continue;
				if (group.standard[0] > resultGroup.standard[0]) {
					resultGroup = group;
					continue;
				}
				if (group.standard[1] < resultGroup.standard[1]) continue;
				resultGroup = group;
			}
		}
		return resultGroup;
	}

	const gravity = function() {
		for (let y = N - 2; y >= 0; y--) {
			for (let x = 0; x < N; x++) {
				if (map[y][x] === EMPTY || map[y][x] === BLACK_BLOCK) continue;
				let temp_y = y;
				while (temp_y + 1 < N && map[temp_y + 1][x] === EMPTY) {
					temp_y++;
				}
				if (temp_y !== y) {
					map[temp_y][x] = map[y][x];
					map[y][x] = EMPTY;
				}
			}
		}
	}

	const rotate = function() {
		const rotated = map.map((line) => line.slice());
		for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++) {
				rotated[N-j-1][i] = map[i][j];
			}
		}
		map = rotated;
	}

	let score = 0;
	while (true) {
		// 블록 그룹 선택하기
		const blockGroup = selectGroup();
		if (blockGroup.blocks.length < 2) {
			break;
		}
		score += Math.pow(blockGroup.blocks.length, 2);
		// 블록 그룹 제거하기
		for (const block of blockGroup.blocks) {
			const [y, x] = block;
			map[y][x] = EMPTY;
		}
		gravity(); // 중력 작용
		rotate(); // 90도 회전
		gravity(); // 중력 작용
	}
	console.log(score);
}