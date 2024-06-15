// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let input;
	for await (const line of rl) {
		input = line;
		rl.close();
	}
	solution(input);
	process.exit();
})();

function solution(input) {
	console.log(input.toString().length);
}
