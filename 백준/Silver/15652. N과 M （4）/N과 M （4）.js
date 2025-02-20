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
    const arr = [];
    const answer = [];

    const repeatedCombination = (next) => {
        if (arr.length === M) {
            answer.push(arr.join(" "));
            return;
        }
        for (let i = next; i <= N; i++) {
            arr.push(i);
            repeatedCombination(i);
            arr.pop();
        }
    }
    repeatedCombination(1);
    console.log(answer.join("\n"));
}
