const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  solution(parseInt(input));
});

function solution(N) {
  const dp = new Array(N);
  dp[0] = 1;
  for (let i = 1; i < N; i++) {
    const candidates = [dp[i - 1] + 1];
    for (let j = 3; i - j >= 0; j++) {
      candidates.push(dp[i - j] * (j - 1));
    }
    dp[i] = Math.max(...candidates);
  }
  console.log(dp[N - 1]);
}
