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
  const works = [];
  for (let i = 1; i <= N; i++) {
    works.push(input[i].split(" ").map(Number));
  }
  solution(N, works);
});

const D = 0;
const T = 1;

const solution = (N, works) => {
  // 마감일 기준 내림차순 정렬
  works.sort((a, b) => b[T] - a[T]);

  let currentDay = works[0][T] - works[0][D];
  for (let i = 1; i < N; i++) {
    if (works[i][T] < currentDay) {
      currentDay = works[i][T];
    }
    currentDay -= works[i][D];
  }
  console.log(currentDay);
};
