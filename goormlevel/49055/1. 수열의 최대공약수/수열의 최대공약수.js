// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	const input = [];
	for await (const line of rl) {
		input.push(line);
	}
	rl.close();
	solution(input);
	process.exit();
})();

function solution(input) {
	const N = parseInt(input[0]);
	const A = input[1].split(' ').map(Number);
	const maxA = A.reduce((accumulator, currentValue) => {
		return Math.max(accumulator, currentValue);
	});
	const commonDivisorCounter = new Array(maxA + 1).fill(0);
	let gcd = 1;
	
	const addCounter = function(divisor) {
		commonDivisorCounter[divisor]++;
		if (commonDivisorCounter[divisor] === A.length && gcd < divisor)
			gcd = divisor;
	}
	
	for (number of A) {
		for (let i = 1; i <= Math.sqrt(number); i++) {
			if (number % i !== 0) continue;
			addCounter(i);
			if (number / i !== i)
				addCounter(number / i);
		}
	}
	
	// divisor가 최대 공약수보다 크고 && count가 2 이상이면서 가장 큰 요소 찾기
	let max_count = 1;
	for (let i = gcd + 1; i <= maxA; i++) {
		if (max_count < commonDivisorCounter[i])
			max_count = commonDivisorCounter[i];
	}
	
	if (max_count === 1)
		console.log(-1);
	else
		console.log(A.length - max_count);
}
