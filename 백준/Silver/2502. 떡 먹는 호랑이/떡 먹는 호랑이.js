const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  const [D, K] = input.split(" ").map(Number);
  solution(D, K);
});

function solution(D, K) {
  // 합쳐서 K가 되며, 다음 조건을 만족하는 두 숫자 A, B를 고른다. (C는 A, B의 차이)
  // - C는 A 이하여야 한다.
  // - C는 A-C 이상이어야 한다. (마지막이 아닌 경우)

  for (let A = 1; A < Math.floor(K / 2); A++) {
    const B = K - A;
    const C = B - A;
    if (A < C) continue;
    if (D === 3) {
      console.log(A);
      console.log(B);
      return;
    }
    if (C < A - C) continue;
    if (D === 4) {
      console.log(C);
      console.log(A);
      return;
    }

    const arr = [K, B, A, C];
    while (arr.length < D) {
      const last1 = arr[arr.length - 1];
      const last2 = arr[arr.length - 2];
      const next = last2 - last1;
      if (next < 1 || last1 < next) break;
      arr.push(last2 - last1);
    }
    if (arr.length === D) {
      console.log(arr[arr.length - 1]);
      console.log(arr[arr.length - 2]);
      return;
    }
  }
}
