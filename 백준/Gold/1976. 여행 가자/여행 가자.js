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
  const M = parseInt(input.shift());
  const plan = input.pop().split(" ").map(Number);
  const graph = input.map((line) => line.split(" ").map(Number));
  solution(N, M, graph, plan);
});

function bfs(reach, startCity, graph, N) {
  const queue = [startCity];
  const visited = new Array(N).fill(false);
  visited[startCity] = true;

  while (queue.length) {
    const city = queue.shift();
    reach[startCity][city] = true;

    for (let i = 0; i < N; i++) {
      if (!graph[city][i] || visited[i]) continue;
      visited[i] = true;
      queue.push(i);
    }
  }
}

function solution(N, M, graph, plan) {
  const reach = new Array(N).fill(null).map(() => Array(N).fill(false));

  for (let i = 0; i < N; i++) {
    bfs(reach, i, graph, N);
  }

  for (let i = 0; i < M - 1; i++) {
    if (!reach[plan[i] - 1][plan[i + 1] - 1]) {
      console.log("NO");
      return;
    }
  }
  console.log("YES");
}
