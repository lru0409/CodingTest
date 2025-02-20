const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, M;
rl.on("line", (line) => {
    [N, M] = line.split(" ").map(Number);
}).on("close", () => {
    solution(N, M);
});

const solution = (N, M) => {
    const p = [];
    const answer = [];

    const repeatedPermutation = () => {
        if (p.length === M) {
            answer.push(p.join(" "));
            return;
        }
        for (let i = 1; i <= N; i++) {
            p.push(i);
            repeatedPermutation();
            p.pop();
        }
    }
    repeatedPermutation();
    console.log(answer.join("\n"));
}
