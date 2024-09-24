const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [N, X] = input[0].split(" ").map(Number);
	const visitors = input[1].split(" ").map(Number);
	solution(N, X, visitors);
});

function solution(N, X, visitors) {
	let currentSum = visitors.slice(0, X).reduce((sum, current) => sum + current, 0);
	let maxSum = currentSum;
	let termCount = 1;

	for (let i = X; i < N; i++) {
		currentSum -= visitors[i - X];
		currentSum += visitors[i];
		if (maxSum < currentSum) {
			termCount = 0;
			maxSum = currentSum;
		}
		if (maxSum <= currentSum) termCount++;
	}

	if (maxSum === 0) console.log('SAD');
	else console.log(`${maxSum}\n${termCount}`);
}