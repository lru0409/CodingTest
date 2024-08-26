const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [N, M, K] = input.shift().split(" ").map(Number);
	const fireBalls = input.map((line) => {
		const [r, c, m, s, d] = line.split(" ").map(Number);
		return { r: r-1, c: c-1, m, s, d };
	});
	solution(N, M, K, fireBalls);
});

const DY = [ -1, -1, 0, 1, 1, 1, 0, -1 ];
const DX = [ 0, 1, 1, 1, 0, -1, -1, -1 ];

function solution(N, M, K, fireBalls) {
	let map = new Array(N).fill(null).map(() => Array(N).fill(null).map(() => Array(0)));
	fireBalls.forEach((ball) => {
		map[ball.r][ball.c].push({m: ball.m, s: ball.s, d: ball.d});
	});

	while (K--) {
		// 파이어볼 이동
		const newMap = new Array(N).fill(null).map(() => Array(N).fill(null).map(() => Array(0)));
		map.forEach((row, r) => {
			row.forEach((square, c) => {
				square.forEach((ball) => {
					const { nr, nc } = moveBall(r, c, ball, N);
					newMap[nr][nc].push(ball);
				});
			});
		});
		map = newMap;
		// 임시 맵을 보고, 2개 이상의 파이어볼이 있는 칸 확인 - 4개의 파이어볼로 나누기
		map.forEach((row) => {
			row.forEach((square, c) => {
				if (square.length < 2) return;
				const { sumM, sumS } = square.reduce(({sumM, sumS}, {m, s}) => {
					sumM += m;
					sumS += s;
					return { sumM, sumS };
				}, {sumM: 0, sumS: 0}); // 질량, 속력의 합
				const isSameDir = square.every(({d}) => square[0].d % 2 === d % 2); // 모두 방향이 같은지 여부
				row[c] = [];
				for (let i = isSameDir ? 0 : 1; i < 8; i+=2) {
					row[c].push({m: Math.floor(sumM/5), s: Math.floor(sumS/square.length), d: i});
				}
			});
		});
		// 질량이 0인 파이어볼 소멸
		map.forEach((row) => {
			row.forEach((square, c) => {
				row[c] = square.filter((ball) => ball.m !== 0);
			});
		});
	}
	// 남아있는 파이어볼 질량의 합
	let sumM = 0;
	map.forEach((row) => {
		row.forEach((square) => {
			sumM += square.reduce((sum, {m}) => sum + m, 0);
		});
	});
	console.log(sumM);
}

function moveBall(r, c, { s, d }, N) {
	const nr = (r + DY[d] * (s % N) + N) % N;
	const nc = (c + DX[d] * (s % N) + N) % N;
	return { nr, nc };
}