const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (line) => {
  const [N, F] = line.split(" ").map(Number);
  solution(N, F);
  rl.close();
});

function solution(N, F) {
  const visited = new Array(N + 1).fill(false);

  const calculate = (p) => {
    let arr = [...p];
    while (1 < arr.length) {
      const nextArr = [];
      for (let i = 0; i < arr.length - 1; i++) {
        nextArr.push(arr[i] + arr[i + 1]);
      }
      arr = nextArr;
    }
    return arr[0] === F;
  };

  const permutation = (p) => {
    if (p.length === N) {
      if (calculate(p)) {
        console.log(p.join(" "));
        process.exit(0);
      }
      return;
    }
    for (let i = 1; i <= N; i++) {
      if (visited[i]) continue;
      visited[i] = true;
      p.push(i);
      permutation(p);
      p.pop();
      visited[i] = false;
    }
  };

  permutation([]);
}
