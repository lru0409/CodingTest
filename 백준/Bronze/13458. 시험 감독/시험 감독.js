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

function solution(input) {
	const N = parseInt(input[0]);
	const A = input[1].split(' ').map(Number);
	const [B, C] = input[2].split(' ').map(Number);

	let answer = 0;
	for (let a of A) {
		a -= B;
		answer += 1;
		if (0 < a) {
			answer += Math.floor(a / C);
			answer += a % C === 0 ? 0 : 1;
		}
	}

	console.log(answer);
}