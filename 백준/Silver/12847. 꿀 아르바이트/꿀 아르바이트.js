const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [n, m] = input[0].split(" ").map(Number);
  const T = input[1].split(" ").map(Number);
  solution(n, m, T);
});

const solution = (n, m, T) => {
  let sum = 0;
  let maxSum = 0;
  for (let i = 0; i < n; i++) {
    sum += T[i];
    if (i - m >= 0) sum -= T[i - m];
    maxSum = Math.max(sum, maxSum);
  }
  console.log(maxSum);
};
