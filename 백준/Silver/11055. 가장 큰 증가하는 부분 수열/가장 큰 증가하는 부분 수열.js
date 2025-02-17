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
  const A = input[1].split(" ").map(Number);
  solution(N, A);
});

const solution = (N, A) => {
  const dp = new Array(N).fill(0);
  dp[0] = A[0];
  let maxResult = A[0];
  for (let current = 1; current < N; current++) {
    let prevMax = 0;
    for (let prev = 0; prev < current; prev++) {
      if (A[prev] < A[current]) prevMax = Math.max(prevMax, dp[prev]);
    }
    dp[current] = prevMax + A[current];
    maxResult = Math.max(maxResult, dp[current]);
  }
  console.log(maxResult);
};
