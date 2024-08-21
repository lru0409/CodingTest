const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [ N, M ] = input.shift().split(" ").map(Number);
	const baskets = input.slice(0, N).map((line) => line.split(" ").map(Number));
	const moveInfo = input.slice(N).map((line) => {
		const [ d, s ] = line.split(" ").map(Number);
		return { d, s };
	});
	solution(baskets, moveInfo, N, M);
});

const DY = [0, -1, -1, -1, 0, 1, 1, 1];
const DX = [-1, -1, 0, 1, 1, 1, 0, -1];

function solution(baskets, moveInfo, N, M) {
	let prevClouds = null;
	let clouds = [{y: N-1, x: 0}, {y: N-1, x: 1}, {y: N-2, x: 0}, {y: N-2, x: 1}];
	
	for (const {d, s} of moveInfo) {
		// 모든 구름이 d방향으로 s칸 이동
		clouds.forEach(cloud => {
			const { y, x } = move(cloud.y, cloud.x, d - 1, s, N);
			cloud.y = y;
			cloud.x = x;
		});
		// 구름이 있는 바구니의 물의 양 1 증가
		const rainyBasckets = [];
		clouds.forEach(({y, x}) => {
			baskets[y][x] += 1;
			rainyBasckets.push({y, x});
		});
		// 구름이 모두 사라짐
		prevClouds = clouds;
		clouds = [];
		// 물이 증가한 칸에 물복사버그 마법 시전
		rainyBasckets.forEach(({y, x}) => {
			waterCopyBugMagic(y, x, baskets, N);
		});
		// 물의 양이 2 이상인 칸에 구름 생성 (구름이 사라진 칸 제외)
		baskets.forEach((row, y) => {
			row.forEach((water, x) => {
				if (water < 2) return;
				if (prevClouds.find((cloud) => cloud.y === y && cloud.x === x)) return;
				baskets[y][x] -= 2;
				clouds.push({y, x});
			});
		});
	}

	// 바구니에 들어있는 물의 합 구하기
	const totalWater = baskets.reduce((sum, row) => {
		return sum + row.reduce((sum, water) => sum + water, 0);
	}, 0);
	console.log(totalWater);
}

function waterCopyBugMagic(y, x, baskets, N) {
	let waterBaskcetCount = 0;
	for (let d = 1; d <= 7; d += 2) { // 1 3 5 7
		const ny = y + DY[d];
		const nx = x + DX[d];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (baskets[ny][nx] > 0) waterBaskcetCount++;
	}
	baskets[y][x] += waterBaskcetCount;
}

function move(y, x, d, s, N) {
	while (s--) {
		y += DY[d];
		x += DX[d];
		if (y < 0) y = N - 1;
		else if (y >= N) y = 0;
		if (x < 0) x = N - 1;
		else if (x >= N) x = 0;
	}
	return { y, x };
}