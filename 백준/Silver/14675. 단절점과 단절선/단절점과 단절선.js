const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = parseInt(input[0]);
  const tree = new Array(N + 1).fill(null).map(() => Array(0));
  for (let i = 1; i < N; i++) {
    const [a, b] = input[i].split(" ").map(Number);
    tree[a].push(b);
    tree[b].push(a);
  }
  const q = parseInt(input[N]);
  const questions = [];
  for (let i = N + 1; i < N + 1 + q; i++) {
    questions.push(input[i].split(" ").map(Number));
  }
  solution(tree, q, questions);
});

function solution(tree, q, questions) {
  const answers = [];
  for (let i = 0; i < q; i++) {
    const [t, k] = questions[i];
    if (t === 2 || tree[k].length >= 2) {
      answers.push("yes");
      continue;
    }
    answers.push("no");
  }
  process.stdout.write(`${answers.join("\n")}\n`);
}
