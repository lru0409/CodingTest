const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

let input;

rl.on('line', (line) => {
	input = line;
}).on('close', () => {
	solution(input);
});

// num1에 num2의 숫자가 순서에 맞게 모두 포함되어 있어야 함
function include(num1, num2) {
	let idx1 = 0;
	let idx2 = 0;
	while (idx1 < num1.length) {
		if (num1[idx1] === num2[idx2]) idx2++;
		idx1++;
	}
	return idx2 === num2.length;
}

function solution(input) {
	let num = 0;
	for (let i = 0; i < input.length; i++) {
		let find = false;
		while (!find) {
			num++;
			const numStr = num.toString();
			for (let len = numStr.length; len >= 1; len--) {
				const subStr = input.substr(i, len);
				if (include(numStr, subStr)) {
					i += len - 1;
					find = true;
					break;
				}
			}
		}
	}
	console.log(num);
}