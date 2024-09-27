const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [document, word] = input;
	solution(document, word);
});

function solution(document, word) {
	let count = 0;

	for (let i = 0; i < document.length; i++) {
		const substr = document.slice(i, i + word.length);
		if (substr === word) {
			i += word.length - 1;
			count++;
		}
	}
	console.log(count);
}