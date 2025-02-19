const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", (close) => {
  const [N, M] = input[0].split(" ").map(Number);
  const A = input.slice(1, N + 1).map((line) => line.split("").map(Number));
  const B = input
    .slice(N + 1, N * 2 + 1)
    .map((line) => line.split("").map(Number));
  solution(N, M, A, B);
});

function solution(N, M, A, B) {
  const flip3x3 = (r, c) => {
    for (let y = 0; y < 3; y++) {
      for (let x = 0; x < 3; x++) {
        const current = A[r + y][c + x];
        A[r + y][c + x] = current === 0 ? 1 : 0;
      }
    }
  };

  let count = 0;
  for (let r = 0; r <= N - 3; r++) {
    for (let c = 0; c <= M - 3; c++) {
      if (A[r][c] !== B[r][c]) {
        flip3x3(r, c);
        count++;
      }
    }
  }
  console.log(A.flat().join("") === B.flat().join("") ? count : -1);
}
