const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  input.shift();
  solution(input);
});

function solution(words) {
  words.sort();

  for (let i = 0; i < words.length - 1; i++) {
    const word = words[i];
    const nextWord = words[i + 1];
    if (nextWord.length < word.length) continue;
    if (word !== nextWord.slice(0, word.length)) continue;
    words.splice(i, 1);
    i--;
  }

  console.log(words.length);
}
