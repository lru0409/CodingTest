const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input.shift());
	const blocks = input.map((line) => {
		const [t, y, x] = line.split(" ").map(Number);
		return {t, x, y};
	});
	solution(N, blocks);
});

function processBoard(board, t, y, x) {
	let score = 0;
	// board에 놓기
	let boardY;
	for (boardY = 0; boardY < 6; boardY++) {
		if ((t == 1 || t == 3) && board[boardY][x]) break;
		if (t == 2 && (board[boardY][x] || board[boardY][x + 1])) break;
	}
	board[boardY - 1][x] = true;
	if (t == 2) board[boardY - 1][x + 1] = true;
	if (t == 3) board[boardY - 2][x] = true;
	// 행이 가득 찼다면 제거
	for (let r = 2; r < 6; r++) {
		const isFull = board[r].every(square => square == true);
		if (!isFull) continue;
		score++;
		for (let pr = r; pr >= 1; pr--) {
			for (let c = 0; c < 4; c++) {
				board[pr][c] = board[pr - 1][c];
			}
		}
		for (let c = 0; c < 4; c++) board[0][c] = false;
	}
	// 연한 부분 처리
	while (true) {
		if (board[0].every(s => !s) && board[1].every(s => !s)) break;
		for (let r = 5; r >= 1; r--) {
			for (let c = 0; c < 4; c++) {
				board[r][c] = board[r - 1][c];
			}
		}
		for (let r = 0; r < 4; r++)
			board[0][r] = false;
	}
	return (score);
}

function solution(N, blocks) {
	const blueBoard = new Array(6).fill(null).map(() => new Array(4).fill(false));
	const greenBoard = new Array(6).fill(null).map(() => new Array(4).fill(false));
	let score = 0;

	for (const {t, x, y} of blocks)
	{
        // console.log(t, y, x);

		// console.log("=====blueBoard=====");
		if (t === 2) {
			score += processBoard(blueBoard, 3, x, 3 - y);
		} else if (t == 3) {
			score += processBoard(blueBoard, 2, x, 3 - y - 1);
		} else {
			score += processBoard(blueBoard, t, x, 3 - y);
		}
		// for (let i = 2; i < 6; i++) {
		// 	console.log(blueBoard[i].map((square) => square ? 'X' : ' '));
		// }
		// console.log("=====greenBoard=====");
		score += processBoard(greenBoard, t, y, x);
		// for (let i = 2; i < 6; i++) {
		// 	console.log(greenBoard[i].map((square) => square ? 'X' : ' '));
		// }
        // console.log("===================================\n");
	}

	const getTileCount = (board) => {
		return board.flat().reduce((count, square) => {
			return count + (square ? 1 : 0);
		}, 0);
	}
	const tileCount = getTileCount(greenBoard) + getTileCount(blueBoard);
	console.log(score + "\n" + tileCount);
}