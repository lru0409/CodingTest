// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let input;
	for await (const line of rl) {
		input = line;
		rl.close();
	}
	solution(parseInt(input));
	process.exit();
})();

function solution(N) {
	const numbers = [ 1 ];
	
	for (let i = 1; i <= N; i++) {
		
		let next = 0;
		for (let j = 0; j < numbers.length; j++) {
			const num = numbers[j] * i;
			numbers[j] = (num + next) % 10;
			next = Math.floor((num + next) / 10);
		}
		while (1 <= next) {
			numbers.push(next % 10);
			next = Math.floor(next / 10);
		}
	}
	
	const getSumArr = function(numbers) {
		let sum = 0;
		for (number of numbers)
			sum += number;
		return sum.toString().split('').map(Number);
	}
	
	let answer = getSumArr(numbers);
	while (1 < answer.length) {
		answer = getSumArr(answer);
	}
	
	console.log(answer[0]);
}
