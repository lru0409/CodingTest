const { stringify } = require('querystring');
const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	solution(input);
})

const EMPTY = 0;

function solution(input) {
	const N = parseInt(input[0]);
	const board = [];

	for (let i = 1; i <= N; i++) {
		board.push(input[i].split(' ').map(Number));
	}

	const copy = function(board) {
		const newBoard = JSON.parse(JSON.stringify(board));
		return newBoard;
	}

	const moveUp = function(board) {
		const isMerged = new Array(N).fill(null).map(() => Array(N).fill(false));
		for (let i = 1; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (board[i][j] === EMPTY) continue;
				let merge_i = i - 1;
				while (0 <= merge_i && board[merge_i][j] === EMPTY) {
					merge_i--;
				}
				if (merge_i + 1 !== i) {
					board[merge_i + 1][j] = board[i][j];
					board[i][j] = EMPTY;
				}
				if (0 <= merge_i && 
					board[merge_i][j] === board[merge_i + 1][j] && 
					isMerged[merge_i][j] === false) {
					board[merge_i][j] *= 2;
					board[merge_i + 1][j] = EMPTY;
					isMerged[merge_i][j] = true;
				}
			}
		}
	}
	const moveDown = function(board) {
		const isMerged = new Array(N).fill(null).map(() => Array(N).fill(false));
		for (let i = N - 2; i >= 0; i--) {
			for (let j = 0; j < N; j++) {
				if (board[i][j] === EMPTY) continue;
				let merge_i = i + 1;
				while (merge_i < N && board[merge_i][j] === EMPTY) {
					merge_i++;
				}
				if (merge_i - 1 !== i) {
					board[merge_i - 1][j] = board[i][j];
					board[i][j] = EMPTY;
				}
				if (merge_i < N && 
					board[merge_i][j] === board[merge_i - 1][j] && 
					isMerged[merge_i][j] === false) {
					board[merge_i][j] *= 2;
					board[merge_i - 1][j] = EMPTY;
					isMerged[merge_i][j] = true;
				}
			}
		}
	}
	const moveLeft = function(board) {
		const isMerged = new Array(N).fill(null).map(() => Array(N).fill(false));
		for (let i = 1; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (board[j][i] === EMPTY) continue;
				let merge_i = i - 1;
				while (0 <= merge_i && board[j][merge_i] === EMPTY) {
					merge_i--;
				}
				if (merge_i + 1 !== i) {
					board[j][merge_i + 1] = board[j][i];
					board[j][i] = EMPTY;
				}
				if (0 <= merge_i && 
					board[j][merge_i] === board[j][merge_i + 1] && 
					isMerged[j][merge_i] === false) {
					board[j][merge_i] *= 2;
					board[j][merge_i + 1] = EMPTY;
					isMerged[j][merge_i] = true;
				}
			}
		}
	}
	const moveRight = function(board) {
		const isMerged = new Array(N).fill(null).map(() => Array(N).fill(false));
		for (let i = N - 2; i >= 0; i--) {
			for (let j = 0; j < N; j++) {
				if (board[j][i] === EMPTY) continue;
				let merge_i = i + 1;
				while (merge_i < N && board[j][merge_i] === EMPTY) {
					merge_i++;
				}
				if (merge_i - 1 !== i) {
					board[j][merge_i - 1] = board[j][i];
					board[j][i] = EMPTY;
				}
				if (merge_i < N && 
					board[j][merge_i] === board[j][merge_i - 1] && 
					isMerged[j][merge_i] === false) {
					board[j][merge_i] *= 2;
					board[j][merge_i - 1] = EMPTY;
					isMerged[j][merge_i] = true;
				}
			}
		}
	}

	let answer = 0;
	const checkMaxBlock = function(board) {
		let maxBlock = 0;
		board.forEach((line) => {
			line.forEach((block) => {
				if (maxBlock < block)
					maxBlock = block;
			})
		})
		answer = Math.max(maxBlock, answer);
	}

	const DFS = function(count, board) {
		if (count === 5) {
			checkMaxBlock(board);
			return;
		}

		const moves = [ moveUp, moveDown, moveLeft, moveRight ];
		for (const move of moves) {
			const newBoard = copy(board);
			move(newBoard);
			DFS(count + 1, newBoard);
		}
	}

	DFS(0, board);
	console.log(answer);
}
