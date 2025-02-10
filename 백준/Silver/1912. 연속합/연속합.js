const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", (close) => {
  const N = parseInt(input[0]);
  const numbers = input[1].split(" ").map(Number);
  solution(N, numbers);
});

const solution = (N, numbers) => {
  // 각 위치에서 해당 숫자를 포함시켰을 때 최댓값을 저장하며 나아가기
  const dp = new Array(N);
  dp[0] = numbers[0];
  let max = numbers[0];
  for (let i = 1; i < N; i++) {
    dp[i] = Math.max(numbers[i], dp[i - 1] + numbers[i]);
    max = Math.max(max, dp[i]);
  }
  console.log(max);
};
