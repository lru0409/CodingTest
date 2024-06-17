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
	const divisorCounter = new Map();
	let gcd = 1;
	
	const addCounter = function(divisor) {
		if (divisorCounter.has(divisor)) {
			divisorCounter.set(divisor, divisorCounter.get(divisor) + 1);
		} else {
			divisorCounter.set(divisor, 1);
		}
		if (divisorCounter.get(divisor) === A.length && gcd < divisor)
			gcd = divisor; // 기존 최대공약수 찾기
	}
	
	// A에서 각 정수의 약수를 찾아 divisorCounter 맵에 합산
	for (number of A) {
		for (let i = 1; i <= Math.sqrt(number); i++) {
			if (number % i === 0) {
				addCounter(i);
				if (number / i !== i)
					addCounter(number / i);
			}
		}
	}
	
	// divisor가 기존 최대공약수보다 크고 && count가 2 이상이면서 가장 큰 요소 찾기
	let maxCount = 1;
	for (const [divisor, count] of divisorCounter) {
		if (gcd < divisor && maxCount < count)
			maxCount = count;
	}
	
	const result = maxCount === 1 ? -1 : A.length - maxCount;
	console.log(result);
}
