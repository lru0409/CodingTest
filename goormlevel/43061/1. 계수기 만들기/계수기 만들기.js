// Run by Node.js

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

const input = [];

rl.on("line", function(line) {
	input.push(line);
}).on("close", function() {
	solution(input);
	process.exit();
});

function solution(input) {
	const N = input[0];
	const A = input[1].split(' ').map(Number);
	const B = input[2].split(' ').map(Number);
	let K = input[3];

	while (K--) {
		let index = N - 1;
		B[index]++;
		while (index >= 0 && B[index] > A[index]) {
			B[index] = 0;
			if (index !== 0)
				B[index - 1]++;
			index--;
		}
	}

	console.log(B.join(''));
}