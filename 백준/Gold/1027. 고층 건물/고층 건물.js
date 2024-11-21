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
  const buildings = input[1].split(" ").map(Number);
  solution(N, buildings);
});

const solution = (N, buildings) => {
  let max = 0;

  // 두 빌딩 간 시야가 확보되는지 확인
  const isVisible = (from, to) => {
    const distY = Math.abs(buildings[from] - buildings[to]);
    const distX = Math.abs(from - to);
    const distYPerX = distY / distX;
    for (let i = 1; i < distX; i++) {
      const possibleY =
        buildings[from] +
        (buildings[from] < buildings[to] ? 1 : -1) * distYPerX * i;
      const currentY = from < to ? buildings[from + i] : buildings[from - i];
      if (possibleY <= currentY) return false;
    }
    return true;
  };

  for (let i = 0; i < N; i++) {
    let count = 0;
    for (let j = 0; j < N; j++) {
      if (i !== j && isVisible(i, j)) count++;
    }
    max = Math.max(max, count);
  }
  console.log(max);
};
