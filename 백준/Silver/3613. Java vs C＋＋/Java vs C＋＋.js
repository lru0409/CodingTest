const { resourceUsage } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

let input;

rl.on('line', (line) => {
	input = line;
	rl.close();
}).on('close', () => {
	solution(input);
})

function solution(input) {

	const isCppWord = function(word) {
		if (word[0] === '_' || word[word.length - 1] === '_')
			return false;
		for (let i = 0; i < word.length; i++) {
			if ((word[i] < 'a' || 'z' < word[i]) && word[i] !== '_')
				return false;
			if (word[i] === '_' && word[i - 1] === '_')
				return false;
		}
		return true;
	}
	const isJavaWord = function(word) {
		if ('A' <= word[0] && word[0] <= 'Z')
			return false;
		for (const c of word) {
			if ((c < 'a' || 'z' < c) && (c < 'A' || 'Z' < c))
				return false;
		}
		return true;
	}

	const cppToJava = function(word) {
		let result = '';
		for (let i = 0; i < word.length; i++) {
			if (word[i] === '_') {
				i++;
				result += word[i].toUpperCase();
			} else {
				result += word[i];
			}
		}
		return result;
	}

	const javaToCpp = function(word) {
		let result = '';
		for (let i = 0; i < word.length; i++) {
			if ('A' <= word[i] && word[i] <= 'Z') {
				result += '_';
				result += word[i].toLowerCase();
			} else {
				result += word[i];
			}
		}
		return result;
	}

	if (input.includes('_')) { // c
		if (!isCppWord(input)) {
			console.log('Error!');
			return;
		}
		console.log(cppToJava(input));
	} else { // java
		if (!isJavaWord(input)) {
			console.log('Error!');
			return;
		}
		console.log(javaToCpp(input));
	}
}