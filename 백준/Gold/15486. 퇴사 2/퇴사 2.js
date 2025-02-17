const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = Number(input.shift());
  const works = input.map((line) => line.split(" ").map(Number));
  solution(N, works);
});

const solution = (N, works) => {
  const dp = new Array(N + 1).fill(0);
  let maxResult = 0;
  for (let today = 0; today < N; today++) {
    const [time, price] = works[today];
    dp[today] = Math.max(dp[today], today === 0 ? 0 : dp[today - 1]);
    if (N < today + time) continue; // 이 상담을 할 날짜가 부족한 경우
    dp[today + time] = Math.max(dp[today + time], dp[today] + price);
    maxResult = Math.max(dp[today + time], maxResult);
  }
  console.log(maxResult);
};
