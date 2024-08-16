const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input[0]);
	const values = input[1].split(' ').map(Number);
	solution(N, values);
});

function solution(N, values) {
	values.sort((a, b) => a - b);
	let left = 0;
	let right = N - 1;
	let minAbs = 2000000000;
	let result;

	while (left < right) {
		const sum = values[left] + values[right];
		if (Math.abs(sum) < minAbs) {
			minAbs = Math.abs(sum);
			result = [ values[left], values[right] ];
		}
		if (0 < sum) { // left + right 가 0보다 크면 -> right 1 감소
			right -= 1;
		} else if (0 > sum) { // left + right 가 0보다 작으면 -> left 1 증가
			left += 1;
		} else { // 0과 같으면 -> 탈출
			break;
		}
	}
	console.log(result.join(" "));
}