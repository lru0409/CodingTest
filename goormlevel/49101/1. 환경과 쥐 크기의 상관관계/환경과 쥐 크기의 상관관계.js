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
	const sizesA = input[1].split(' ').map(Number);
	const sizesB = input[2].split(' ').map(Number);
	
	const getValue = function(sizes) { // 대표값 구하기

		sizes.sort((a, b) => a - b);
		const min = sizes[0];
		const max = sizes[sizes.length - 1];

		let start = 0;
		let end = 0;
		let maxCount = 0;
		let value;

		for (let num = min; num <= max; num++) {
			while (sizes[start] < num - 2)
				start++;
			while (end < sizes.length && sizes[end] <= num + 2)
				end++;
			if (maxCount < end - start) {
				maxCount = end - start;
				value = num;
			}
		}
		return value;
	}
	
	const valueA = getValue(sizesA);
	const valueB = getValue(sizesB);
	
	console.log(valueA, valueB);
	if (valueA > valueB)
		console.log('good');
	else
		console.log('bad');
}
