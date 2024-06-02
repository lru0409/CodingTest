const readline = require('readline').createInterface({
	input: process.stdin,
	output: process.stdout,
})

let input;

readline.on('line', function(line) {
	input = line;
	readline.close();
}).on('close', function() {
	Solution(input.split(' ').map(Number));
})

function Solution(dice) {

	const scores = [
		2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 
		22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 
		13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35
	];
	const board = [
		[1], [2], [3], [4], [5, 20], [6], [7], [8], [9], [10, 23],
		[11], [12], [13], [14], [15, 25], [16], [17], [18], [19], [-1],
		[21], [22], [28], [24], [28], [26], [27], [28], [29], [30], [19]
	];
	
	const move = function(start, count) {
		let current = start;
		let next = board[start].length === 1 ? board[start][0] : board[start][1];
		while (count--) {
			current = next;
			if (current < 0) break;
			next = board[current][0];
		}
		return current;
	}

	const isAvailabe = (position, horses) => !horses.includes(position);

	let maxScore = 0;
	
	const BFS = function() {
		const queue = [ [0, 0, []] ]; // 주사위 인덱스, 점수, 말 위치

		while (queue.length) {
			const [diceIndex, score, horses] = queue.shift();

			if (diceIndex === dice.length) {
				maxScore = Math.max(score, maxScore);
				continue;
			}

			// 기존 말 옮기기
			for (let i = 0; i < horses.length; i++) {
				if (horses[i] === -1) continue;
				const next = move(horses[i], dice[diceIndex]);
				if (next !== -1 && !isAvailabe(next, horses)) continue;
				const newHorses = [...horses];
				newHorses[i] = next;
				let newScore = next === -1 ? score : score + scores[next];
				queue.push([diceIndex + 1, newScore, newHorses]);
			}

			// 새로운 말 꺼내기
			if (horses.length === 4) continue;
			const next = move(0, dice[diceIndex] - 1);
			if (!isAvailabe(next, horses)) continue;
			const newHorses = [...horses, next];
			queue.push([diceIndex + 1, score + scores[next], newHorses]);
		}
	}

	BFS();
	console.log(maxScore);
}