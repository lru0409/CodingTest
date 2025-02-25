const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
rl.on("line", (line) => {
  N = Number(line);
}).on("close", () => {
  solution(N);
});

// DP[a][b] = 길이가 a 일 때 마지막 수가 b일 경우의 계단의 수
// DP[a][b] = DP[a-1][b-1](b가 0인 경우 x) + DP[a-1][b+1](b가 9인 경우 x)

const solution = (N) => {
  const dp = new Array(N + 1).fill(null).map(() => new Array(10).fill(0));
  for (let i = 1; i <= 9; i++) dp[1][i] = 1;

  for (let a = 2; a <= N; a++) {
    for (let b = 0; b <= 9; b++) {
      if (b === 0) dp[a][b] = dp[a - 1][b + 1];
      else if (b === 9) dp[a][b] = dp[a - 1][b - 1];
      else dp[a][b] = (dp[a - 1][b + 1] + dp[a - 1][b - 1]) % 1000000000;
    }
  }
  console.log(dp[N].reduce((acc, current) => (acc + current) % 1000000000, 0));
};
