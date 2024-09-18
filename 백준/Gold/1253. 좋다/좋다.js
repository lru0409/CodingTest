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

function solution(N, A) {
  A.sort((a, b) => a - b);

  let count = 0;
  for (let i = 0; i < N; i++) {
    const a = A.slice(0, i).concat(A.slice(i + 1));
    let start = 0;
    let end = a.length - 1;
    while (start < end) {
      const sum = a[start] + a[end];
      if (sum === A[i]) {
        count++;
        break;
      } else if (sum < A[i]) {
        start += 1;
      } else {
        end -= 1;
      }
    }
  }
  console.log(count);
}
