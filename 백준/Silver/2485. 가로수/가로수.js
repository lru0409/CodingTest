const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = parseInt(input.shift());
  const positions = input.map(Number);
  positions.sort((a, b) => a - b);
  solution(N, positions);
});

function greatestCommonDivisor(num1, num2) {
  const smaller = Math.min(num1, num2);
  const bigger = Math.max(num1, num2);
  for (let i = 1; i < smaller; i++) {
    if (smaller % i !== 0) continue;
    const divisor = smaller / i;
    if (bigger % divisor === 0) return divisor;
  }
  return 1;
}

function solution(N, positions) {
  // 간격 간의 최대공약수 찾기
  let gcd = positions[1] - positions[0];
  let longestDist = Math.max(positions[0], positions[1]);
  let shortestDist = Math.min(positions[0], positions[1]);
  for (let i = 2; i < N; i++) {
    gcd = greatestCommonDivisor(gcd, positions[i] - positions[i - 1]);
    longestDist = Math.max(longestDist, positions[i]);
    shortestDist = Math.min(shortestDist, positions[i]);
  }

  // 총 거리를 해당 간격으로 나누고, 더 심어야 하는 개수 구하기
  const count = (longestDist - shortestDist) / gcd + 1; // 필요한 총 가로수 개수
  console.log(count - N); // 더 심어야 하는 개수
}
