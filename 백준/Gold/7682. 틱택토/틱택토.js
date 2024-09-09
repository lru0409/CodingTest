const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	input.pop();
	const cases = input.map((line) => {
		const board = new Array(3).fill(null).map(() => Array(3));
		let oCount = 0;
		let xCount = 0;
		for (let i = 0; i < line.length; i++) {
			board[Math.floor(i / 3)][i % 3] = line[i];
			if (line[i] == 'O') oCount++;
			else if (line[i] == 'X') xCount++;
		}
		return { board, oCount, xCount };
	});
	solution(cases);
});

function solution(cases) {
	cases.forEach(({ board, oCount, xCount }) => {
		// X와 O의 개수가 같거나, X가 한 개 더 많아야 한다
		if (oCount != xCount && oCount + 1 != xCount) {
			console.log("invalid");
			return;
		}
		const oSuccess = [];
		const xSuccess = [];
		for (let y = 0; y < 3; y++) {
			if (board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
				if (board[y][0] == 'O') oSuccess.push([[y, 0], [y, 1], [y, 2]]);
				else if (board[y][0] == 'X') xSuccess.push([[y, 0], [y, 1], [y, 2]]);
			}
		}
		for (let x = 0; x < 3; x++) {
			if (board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
				if (board[0][x] == 'O') oSuccess.push([[0, x], [1, x], [2, x]]);
				else if (board[0][x] == 'X') xSuccess.push([[0, x], [1, x], [2, x]]);
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			if (board[0][0] == 'O') oSuccess.push([[0, 0], [1, 1], [2, 2]]);
			else if (board[0][0] == 'X') xSuccess.push([[0, 0], [1, 1], [2, 2]]);
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			if (board[0][2] == 'O') oSuccess.push([[0, 2], [1, 1], [2, 0]]);
			else if (board[0][2] == 'X') xSuccess.push([[0, 2], [1, 1], [2, 0]]);
		}
		// 둘 다 성공했으면 안 된다.
		if (oSuccess.length && xSuccess.length) {
			console.log("invalid");
			return;
		}
		// X는 두 개 이상 성공할 수 있다. 다만 두 줄에서 중복되는 위치가 있어야 한다.
		if (xSuccess.length == 2) {
			const duplicated = xSuccess[0].find((pos1) => {
				let duplicated = false;
				xSuccess[1].forEach((pos2) => {
					if (pos1[0] == pos2[0] && pos1[1] == pos2[1])
						duplicated = true;
				});
				return duplicated;
			});
			if (!duplicated) {
				console.log("invalid");
				return;
			}
		}
		// O가 이긴 경우, X와 O의 개수가 같아야 한다.
		if (oSuccess.length && oCount != xCount) {
			console.log("invalid");
			return;
		}
		// X가 이긴 경우, X가 O보다 1개 더 많아야 한다.
		if (xSuccess.length && oCount + 1 != xCount) {
			console.log("invalid");
			return;
		}
		// 최종 상태(누군가 이겼거나, 판이 다 참)여야 한다.
		if (!oSuccess.length && !xSuccess.length && oCount + xCount != 9) {
			console.log("invalid");
			return;
		}
		console.log("valid");
	});
}