const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  const N = parseInt(input);
  solution(N);
});

const solution = (N) => {
  const dp = new Array(N + 1).fill(Infinity);
  dp[1] = [1];
  for (let i = 2; i <= N; i++) {
    let prev = dp[i - 1];
    if (i % 2 === 0 && dp[i / 2].length < prev.length) prev = dp[i / 2];
    if (i % 3 === 0 && dp[i / 3].length < prev.length) prev = dp[i / 3];
    dp[i] = prev.concat(i);
  }
  console.log(dp[N].length - 1);
  console.log(dp[N].reverse().join(" "));
};
