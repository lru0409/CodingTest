const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [N, K] = input[0].split(" ").map(Number);
  const possibles = input[1].split(" ").map(Number);
  const missions = input[2].split(" ").map(Number);
  solution(N, K, possibles, missions);
});

const solution = (N, K, possibles, missions) => {
  const angles = new Array(360).fill(false);

  const dfs = (value) => {
    if (value < 0) return;
    if (angles[value]) return;
    angles[value] = true;
    for (let i = 0; i < N; i++) {
      dfs((value + possibles[i]) % 360);
      dfs(value - possibles[i]);
    }
  };
  dfs(0);

  for (let i = 0; i < K; i++) {
    console.log(angles[missions[i]] ? "YES" : "NO");
  }
};
