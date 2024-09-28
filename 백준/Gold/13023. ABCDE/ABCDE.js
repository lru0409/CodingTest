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
  const friendGraph = new Array(N).fill(null).map(() => new Array(0));
  input.map((line) => {
    const [p1, p2] = line.split(" ").map(Number);
    friendGraph[p1].push(p2);
    friendGraph[p2].push(p1);
  });
  solution(N, friendGraph);
});

function DFS(person, friendGraph, visited, count) {
  if (count === 4) {
    return true;
  }
  for (let i = 0; i < friendGraph[person].length; i++) {
    if (visited[friendGraph[person][i]]) continue;
    visited[friendGraph[person][i]] = true;
    if (DFS(friendGraph[person][i], friendGraph, visited, count + 1))
      return true;
    visited[friendGraph[person][i]] = false;
  }
  return false;
}

function solution(N, friendGraph) {
  const visited = new Array(N).fill(false);
  for (let i = 0; i < N; i++) {
    visited[i] = true;
    if (DFS(i, friendGraph, visited, 0)) {
      console.log(1);
      return;
    }
    visited[i] = false;
  }
  console.log(0);
}
