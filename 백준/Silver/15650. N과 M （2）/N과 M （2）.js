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

    const combination = (next) => {
        if (arr.length === M) {
            console.log(arr.join(" "));
            return;
        }
        for (let i = next; i <= N; i++) {
            arr.push(i);
            combination(i + 1);
            arr.pop();
        }
    }
    combination(1);
}
