const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input.shift());
	solution(N, input);
});

const DY = [0, 0, 1, -1]; // 동서남북 순
const DX = [1, -1, 0, 0];

function solution(N, map) {
	// 문 2개 위치 찾기
	const doors = [];
	for (let y = 0; y < N; y++) {
		for (let x = 0; x < N; x++) {
			if (map[y][x] === '#') doors.push({ y, x });
		}
	}

	const minMirror = new Array(N).fill(null).map(() => Array(N).fill(null).map(() => Array(4).fill(Infinity)));
	const data = { mirror: 0, y: doors[0].y, x: doors[0].x };
	const queue = [];
	for (let i = 0; i < 4; i++) {
		queue.push({ ...data, dir: i });
	}
	while (queue.length) {
		queue.sort((a, b) => a.mirror - b.mirror);
		const {dir, mirror, y, x} = queue.shift();

		if (minMirror[y][x][dir] <= mirror) continue;
		if (y === doors[1].y && x === doors[1].x) {
			minMirror[y][x][dir] = mirror;
			continue;
		}

		// ! 가 아닌 경우 : 가던 방향으로 나아가기
		if (map[y][x] !== '!') {
			const ny = y + DY[dir];
			const nx = x + DX[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] === '*') continue;
			minMirror[y][x][dir] = mirror;
			queue.push({ dir, mirror, y: ny, x: nx });
			continue;
		}

		// ! 인 경우 : 가던 방향으로 나아가거나 우회전/좌회전 가능
		for (let i = 0; i < 4; i++) {
			if (dir % 2 === 0 && i === dir + 1) continue;
			if (dir % 2 !== 0 && i === dir - 1) continue;
			const newMirror = i === dir ? mirror : mirror + 1;
			const ny = y + DY[i];
			const nx = x + DX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] === '*') continue;
			if (minMirror[ny][nx][i] <= newMirror) continue;
			minMirror[y][x][dir] = newMirror;
			queue.push({ dir: i, mirror: newMirror, y: ny, x: nx });
		}
	}

	console.log(Math.min(...(minMirror[doors[1].y][doors[1].x])));
}