const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = Number(input.shift());
  solution(N, input);
});

function solution(N, input) {
  let maxCount = 0;
  for (let i = 0; i < N; i++) {
    const person = input[i];
    let friends = new Set();
    for (let j = 0; j < N; j++) {
      if (i === j || person[j] === "N") continue;
      const friend = j;
      friends.add(friend); // 친구
      for (let k = 0; k < N; k++) {
        if (j === k || i === k || input[friend][k] === "N") continue;
        friends.add(k); // 친구의 친구
      }
    }
    maxCount = Math.max(maxCount, friends.size);
  }
  console.log(maxCount);
}
