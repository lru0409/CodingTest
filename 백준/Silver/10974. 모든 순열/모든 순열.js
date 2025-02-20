const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;
rl.on("line", (line) => {
    N = Number(line);
}).on("close", (close) => {
    solution(N);
});

const solution = (N) => {
    let p = [];
    const visited = new Array(N + 1).fill(false);

    const permutation = () => {
        if (p.length === N) {
            console.log(p.join(" "));
            return;
        }
        for (let i = 1; i <= N; i++) {
            if (visited[i]) continue;
            p.push(i);
            visited[i] = true;
            permutation();
            visited[i] = false;
            p.pop();
        }
    }
    permutation();
}
