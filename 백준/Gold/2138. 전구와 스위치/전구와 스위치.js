const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input.shift());
	const current = input.shift().split('').map(Number);
	const goal = input.shift().split('').map(Number);
	solution(N, current, goal);
});

function press(current, num, N) {
	for (let i = -1; i <= 1; i++) {
		if (num + i < 0 || N <= num + i) continue;
		current[num + i] = current[num + i] ? 0 : 1;
	}
	return current;
}

function pressToGoal(current, goal, count, N) {
	for (let i = 1; i < N; i++) {
		if (current[i - 1] === goal[i - 1]) continue;
		count++;
		press(current, i, N);
	}
	const same = current.every((bulb, index) => goal[index] === bulb);
	return { same, count };
}

function solution(N, current, goal) {
	let minCount = N + 1;

	// 0번 스위치를 누르는 상황
	const pressZero = press(current.slice(), 0, N);
	let result1 = pressToGoal(pressZero, goal, 1, N);
	if (result1.same) minCount = Math.min(minCount, result1.count);

	// // 0번 스위치를 누르지 않는 상황
	const result2 = pressToGoal(current.slice(), goal, 0, N);
	if (result2.same) minCount = Math.min(minCount, result2.count);

	console.log(minCount === N + 1 ? -1 : minCount);
}