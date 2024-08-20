const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input.shift());
	const city = input.map((row) => row.split(" ").map(Number));
	solution(N, city);
});

function solution(N, city) {
	let result = 40000;

	// x, y는 1 이상 N 이하여야 함
	for (let x = 1; x <= N; x++) {
		for (let y = 1; y <= N; y++) {
			// d1은 1 이상, y - 1 이하, N - x 이하여야 함
			const d1Max = Math.min(y - 1, N - x);
			for (let d1 = 1; d1 <= d1Max; d1++) {
				// d2는 1 이상, N - y 이하, N - x - d1 이하여야 함
				const d2Max = Math.min(N - y, N - x - d1);
				for (let d2 = 1; d2 < d2Max; d2++) {
					const populations = getPopulations(city, N, x - 1, y - 1, d1, d2);
					const minPop = Math.min(...populations);
					const maxPop = Math.max(...populations);
					result = Math.min(result, maxPop - minPop);
				}
			}
		}
	}
	console.log(result);
}

function getPopulations(city, N, x, y, d1, d2) {
	// 경계선 체크
	const border = new Array(N).fill(null).map(() => Array(N).fill(false));
	for (let i = 0; i <= d1; i++) {
		border[y - i][x + i] = true;
		border[y + d2 - i][x + d2 + i] = true;
	}
	for (let i = 0; i <= d2; i++) {
		border[y + i][x + i] = true;
		border[y - d1 + i][x + d1 + i] = true;
	}

	const populations = new Array(5).fill(0);
	// 1선거구
	for (let r = 0; r < y; r++) {
		for (let c = 0; c <= x + d1; c++) {
			if (border[r][c]) break;
			populations[0] += city[r][c];
		}
	}
	// 2선거구
	for (let r = 0; r <= y - d1 + d2; r++) {
		for (let c = N - 1; c > x + d1; c--) {
			if (border[r][c]) break;
			populations[1] += city[r][c];
		}
	}
	// 3선거구
	for (let r = y; r < N; r++) {
		for (let c = 0; c < x + d2; c++) {
			if (border[r][c]) break;
			populations[2] += city[r][c];
		}
	}
	// 4선거구
	for (let r = y + d2 - d1 + 1; r < N; r++) {
		for (let c = N - 1; c >= x + d2; c--) {
			if (border[r][c]) break;
			populations[3] += city[r][c];
		}
	}
	// 5선거구
	const total = city.reduce((sum, line) => {
		return sum + line.reduce((sum, square) => sum + square, 0);
	}, 0);
	populations[4] = populations.reduce((acc, pop) => acc - pop, total);
	return populations;
}