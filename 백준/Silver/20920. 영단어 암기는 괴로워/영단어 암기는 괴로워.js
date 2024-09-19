const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [N, M] = input.shift().split(" ").map(Number);
	solution(N, M, input);
});


function solution(N, M, words) {
	const counter = {};
	const properWords = [];

	words.forEach((word) => {
		if (word.length < M) return;
		if (counter.hasOwnProperty(word)) {
			counter[word] += 1;
		} else {
			counter[word] = 1;
			properWords.push(word);
		}
	});

	properWords.sort((a, b) => {
		if (counter[a] !== counter[b])
			return counter[b] - counter[a];
		if (a.length !== b.length)
			return b.length - a.length;
		return a.localeCompare(b);
	});

	console.log(properWords.join("\n"));
}