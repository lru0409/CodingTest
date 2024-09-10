const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

let input;

rl.on('line', (line) => {
	input = line;
}).on('close', () => {
	const [N, a, b] = input.split(" ").map(Number);
	solution(N, a, b);
});

function solution(N, a, b) {
	const buildings = [];

	if (a >= 2) {
		for (let i = 0; i < N - (a + b - 1); i++) {
			buildings.push(1);
		}
	}
	for (let i = 1; i <= a - 1; i++)
		buildings.push(i);
	buildings.push(Math.max(a, b));
	if (a === 1) {
		for (let i = 0; i < (N - a) - (b - 1); i++) {
			buildings.push(1);
		}
	}
	for (let i = b - 1; i >= 1; i--)
		buildings.push(i);

	if (buildings.length !== N) {
		console.log(-1);
		return;
	}

	console.log(buildings.join(" "));
}