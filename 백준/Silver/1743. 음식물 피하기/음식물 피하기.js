const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [N, M, K] = input[0].split(" ").map(Number);
  const map = new Array(N).fill(null).map(() => new Array(M).fill("."));
  for (let i = 1; i <= K; i++) {
    const [y, x] = input[i].split(" ").map((c) => Number(c) - 1);
    map[y][x] = "#";
  }
  solution(N, M, map);
});

const DY = [-1, 1, 0, 0];
const DX = [0, 0, -1, 1];

const solution = (N, M, map) => {
  const visited = new Array(N).fill(null).map(() => new Array(M).fill(false));
  let answer = 0;

  const BFS = (startY, startX) => {
    const queue = [[startY, startX]];
    let size = 0;
    while (queue.length > 0) {
      const [y, x] = queue.shift();
      size++;
      for (let dir = 0; dir < 4; dir++) {
        const ny = y + DY[dir];
        const nx = x + DX[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] !== "#" || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        queue.push([ny, nx]);
      }
    }
    return size;
  };

  const DFS = (y, x) => {
    let size = 1;
    for (let dir = 0; dir < 4; dir++) {
      const ny = y + DY[dir];
      const nx = x + DX[dir];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (map[ny][nx] !== "#" || visited[ny][nx]) continue;
      visited[ny][nx] = true;
      size += DFS(ny, nx);
    }
    return size;
  };

  for (let y = 0; y < N; y++) {
    for (let x = 0; x < M; x++) {
      if (visited[y][x] || map[y][x] !== "#") continue;
      visited[y][x] = true;
      answer = Math.max(answer, DFS(y, x));
    }
  }
  console.log(answer);
};
