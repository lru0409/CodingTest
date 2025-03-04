const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [N, S, M] = input[0].split(" ").map(Number);
  const V = input[1].split(" ").map(Number);
  solution(N, S, M, V);
});

function solution(N, S, M, V) {
  const visited = new Array(N)
    .fill(null)
    .map(() => new Array(M + 1).fill(false));

  const dfs = (v, count) => {
    if (count === N) return;

    let nextV = v + V[count];
    if (nextV <= M && !visited[count][nextV]) {
      visited[count][nextV] = true;
      dfs(nextV, count + 1);
    }
    nextV = v - V[count];
    if (0 <= nextV && !visited[count][nextV]) {
      visited[count][nextV] = true;
      dfs(nextV, count + 1);
    }
  };
  dfs(S, 0);

  for (let v = M; v >= 0; v--) {
    if (visited[N - 1][v]) {
      console.log(v);
      return;
    }
  }
  console.log(-1);
}
