const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
    const [N, M] = input.shift().split(" ").map(Number);
    solution(N, M, input.map((line) => line.split(" ").map(Number)));
});

const DY = [0, 1];
const DX = [1, 0];

function solution(N, M, map) {
    const bfs = () => {
        const queue = [[0, 0, 0]]; // y, x, count
        const visited = new Array(N).fill(null).map(() => new Array(M).fill(false));
        while (queue.length) {
            const [y, x, count] = queue.shift();
            if (y === N - 1 && x === M - 1) return count;
            const busterCount = map[y][x];
            for (let dir = 0; dir < 2; dir++) {
                for (let moveCount = 1; moveCount <= busterCount; moveCount++) {
                    const ny = y + (DY[dir] * moveCount);
                    const nx = x + (DX[dir] * moveCount);
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
                    if (visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    queue.push([ny, nx, count + 1]);
                }
            }
        }
    }
    console.log(bfs());
}