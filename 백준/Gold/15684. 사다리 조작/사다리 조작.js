const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

const input = [];

rl.on("line", (line) => {
	input.push(line);
}).on("close", () => {
	solution(input);
})


function solution(input) {
	const [N, M, H] = input[0].split(' ').map(Number);
	const verLine = new Array(H).fill(null).map(() => Array(N - 1).fill(false));

	for (let i = 1; i <= M; i++) {
		const [a, b] = input[i].split(' ').map(Number);
		verLine[a - 1][b - 1] = true;
	}

	let maxCount = 4; // 추가해야 하는 가로선의 최솟값

	const check = function(depth) {
		for (let hoLine = 0; hoLine < N; hoLine++) {
			let y = 0, x = hoLine;
			while (y < H) {
				if (x - 1 >= 0 && verLine[y][x - 1]) {
					x -= 1;
				} else if (verLine[y][x]) {
					x += 1;
				}
				y++;
			}
			if (x !== hoLine) return;
		}
		maxCount = Math.min(depth, maxCount);
	}

	const DFS = function(depth, nextI, nextJ) {
		check(depth);
		if (depth === 3) {
			return;
		}
		for (let i = nextI; i < H; i++) {
			for (let j = nextJ; j < N - 1; j++) {
				if (verLine[i][j] === true) continue;
				if (j - 1 >= 0 && verLine[i][j - 1] === true) continue;
				if (j + 1 < N - 1 && verLine[i][j + 1] === true) continue;
				verLine[i][j] = true;
				DFS(depth + 1, i, j + 1);
				verLine[i][j] = false;
			}
			nextJ = 0;
		}
	}

	DFS(0, 0, 0);
	console.log(`${maxCount === 4 ? -1 : maxCount}`);
}