const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [R, C, K] = input[0].split(" ").map(Number);
  const map = [];
  for (let i = 1; i <= R; i++) {
    map.push(input[i].split(""));
  }
  solution(R, C, K, map);
});

const DY = [-1, 1, 0, 0];
const DX = [0, 0, -1, 1];

function solution(R, C, K, map) {
  let count = 0;
  const dfs = (y, x, dist, visited) => {
    if (y === 0 && x == C - 1 && dist === K) {
      count++;
      return;
    }
    if (K <= dist) return;
    for (let dir = 0; dir < 4; dir++) {
      const ny = y + DY[dir];
      const nx = x + DX[dir];
      if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
      if (map[ny][nx] === "T" || visited[ny][nx]) continue;
      visited[ny][nx] = true;
      dfs(ny, nx, dist + 1, visited);
      visited[ny][nx] = false;
    }
  };
  const visited = new Array(R).fill(null).map(() => new Array(C).fill(false));
  visited[R - 1][0] = true;
  dfs(R - 1, 0, 1, visited);
  console.log(count);
}
