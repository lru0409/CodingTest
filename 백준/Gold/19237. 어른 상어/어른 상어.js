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

const DIR_Y = [ -1, 1, 0, 0 ];
const DIR_X = [ 0, 0, -1, 1 ];

const EMPTY = -1;

function solution(input) {
	const [N, M, k] = input[0].split(' ').map(Number);
	// 각 상어의 위치, 방향, 방향 우선순위
	const sharks = new Array(M).fill(null).map(() => {
		return {
			pos: null,
			dir: null,
			dirPriority: []
		}
	});
	const smell = [];
	const map = new Array(N).fill(null).map(() => Array(N).fill(null).map(() => Array(0)));
	for (let i = 1; i <= N; i++) {
		const line = input[i].split(' ').map(Number);
		line.forEach((num, index) => {
			if (num !== 0) {
				sharks[num - 1].pos = [i - 1, index];
				map[i - 1][index].push(num - 1);
			}
		});
		smell.push(line.map((n) => [parseInt(n) - 1, k]));
	}
	input[N + 1].split(' ').map(Number).forEach((dir, index) => {
		sharks[index].dir = dir - 1;
	});
	for (let i = N + 2; i < N + 2 + (M * 4); i++) {
		const index = Math.floor((i - (N + 2)) / 4);
		sharks[index].dirPriority.push(input[i].split(' ').map((dir) => parseInt(dir) - 1));
	}
	
	const moveShark = function(index) {
		const [cy, cx] = sharks[index].pos;
		const dirPriority = sharks[index].dirPriority[sharks[index].dir];
		let decided = null;
		for (const dir of dirPriority) {
			const ny = cy + DIR_Y[dir];
			const nx = cx + DIR_X[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (smell[ny][nx][0] === EMPTY) {
				decided = { ny, nx, dir};
				break;
			}
			if (decided === null && smell[ny][nx][0] === index) {
				decided = { ny, nx, dir};
			}
		}
		sharks[index].pos = [ decided.ny, decided.nx ];
		sharks[index].dir = decided.dir;
		map[cy][cx] = map[cy][cx].filter((n) => n !== index);
		map[decided.ny][decided.nx].push(index);
	}
	
	let second = 0;
	while (true) {
		// 1번 상어만 남았는지 확인
		const count = sharks.reduce((acc, current) => {
			if (current === null) return acc;
			return acc + 1;
		}, 0);
		if (count === 1)
			break;
		if (second === 1000) {
			console.log(-1);
			return;
		}
		// 상어 이동
		for (let i = 0; i < M; i++) {
			if (sharks[i] === null) continue;
			moveShark(i);
		}
		// 냄새 감소시키기
		for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (smell[i][j][0] === EMPTY) continue;
				smell[i][j][1]--;
				if (smell[i][j][1] === 0) {
					smell[i][j][0] = EMPTY;
				}
			}
		}
		// 상어 쫓아내기
		for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (map[i][j].length < 2) continue;
				map[i][j].sort((a, b) => a - b);
				const count = map[i][j].length;
				for (let k = 0; k < count - 1; k++) {
					const index = map[i][j].pop();
					sharks[index] = null;
				}
			}
		}
		// 이동한 곳에 냄새 뿌리기
		for (let i = 0; i < M; i++) {
			if (sharks[i] === null) continue;
			smell[sharks[i].pos[0]][sharks[i].pos[1]] = [i, k];
		}
		second++;
	}

	console.log(second);
}