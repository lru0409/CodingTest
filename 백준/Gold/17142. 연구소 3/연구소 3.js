const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [ N, M ] = input.shift().split(" ").map(Number);
	const map = input.map((line) => line.split(" ").map(Number));
	solution(N, M, map);
});

const EMPTY = 0, WALL = 1, VIRUS = 2, ACTIVE_VIRUS = 3;
const DY = [ -1, 1, 0, 0 ];
const DX = [ 0, 0, -1, 1 ];
let minTime = Infinity;

function solution(N, M, map) {
	// 바이러스의 위치 알아내기
	const virus = [];
	map.forEach((line, y) => {
		line.forEach((sqaure, x) => {
			if (sqaure === VIRUS) virus.push([y, x]);
		});
	});

	// M개의 바이러스를 활성 상태로 만드는 조합의 경우의 수 구하기
	selectVirus([], 0, M, virus, map);
	console.log(minTime === Infinity ? -1 : minTime);
}

function selectVirus(selected, next, M, virus, map) {
	if (selected.length === M) {
		const spreadTime = spreadVirus(selected, map);
		minTime = Math.min(minTime, spreadTime);
		return;
	}
	for (let i = next; i < virus.length; i++) {
		selected.push(virus[i]);
		selectVirus(selected, i + 1, M, virus, map);
		selected.pop();
	}
}

function spreadVirus(virus, originMap) {
	const map = originMap.map((line) => line.map((square) => square));

	const queue = virus.map(([ny, nx]) => [ny, nx, 0]);
	const visited = new Array(map.length).fill(null).map(() => Array(map.length).fill(false));
	virus.forEach(([y, x]) => {
		visited[y][x] = true;
		map[y][x] = ACTIVE_VIRUS;
	});

	let spreadTime = 0;
	while (queue.length) {
		const [cy, cx, time] = queue.shift();
		if (originMap[cy][cx] !== VIRUS) {
			spreadTime = Math.max(spreadTime, time);
		}

		for (let i = 0; i < 4; i++) {
			const ny = cy + DY[i], nx = cx + DX[i];
			if (ny < 0 || nx < 0 || ny >= map.length || nx >= map.length) continue;
			if (visited[ny][nx] || map[ny][nx] === WALL) continue;
			visited[ny][nx] = true;
			map[ny][nx] = ACTIVE_VIRUS;
			queue.push([ny, nx, time + 1]);
		}
	}

	const isAllSpread = map.every((line) => {
		return line.every((square) => square !== EMPTY);
	});
	return isAllSpread ? spreadTime : Infinity;
}
