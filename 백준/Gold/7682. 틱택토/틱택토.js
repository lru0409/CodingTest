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
		let oSuccess = false;
		let xSuccess = false;
		for (let y = 0; y < 3; y++) {
			if (board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
				if (board[y][0] == 'O') oSuccess = true;
				else if (board[y][0] == 'X') xSuccess = true;
			}
		}
		for (let x = 0; x < 3; x++) {
			if (board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
				if (board[0][x] == 'O') oSuccess = true;
				else if (board[0][x] == 'X') xSuccess = true;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			if (board[0][0] == 'O') oSuccess = true;
			else if (board[0][0] == 'X') xSuccess = true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			if (board[0][2] == 'O') oSuccess = true;
			else if (board[0][2] == 'X') xSuccess = true;
		}
		// 둘 다 성공했으면 안 된다.
		if (oSuccess && xSuccess) {
			console.log("invalid");
			return;
		}
		// O가 이긴 경우, X와 O의 개수가 같아야 한다.
		if (oSuccess && oCount != xCount) {
			console.log("invalid");
			return;
		}
		// X가 이긴 경우, X가 O보다 1개 더 많아야 한다.
		if (xSuccess && oCount + 1 != xCount) {
			console.log("invalid");
			return;
		}
		// 최종 상태(누군가 이겼거나, 판이 다 참)여야 한다.
		if (!oSuccess && !xSuccess && oCount + xCount != 9) {
			console.log("invalid");
			return;
		}
		console.log("valid");
	});
}