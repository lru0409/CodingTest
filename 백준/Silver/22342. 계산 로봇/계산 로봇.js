const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
    const [M, N] = input[0].split(" ").map(Number);
    const weight = [];
    for (let i = 1; i <= M; i++) {
        weight.push(input[i].split("").map(Number));
    }
    solution(M, N, weight);
});

const DY = [0, -1, 1];
const DX = [-1, -1, -1];

const solution = (M, N, weight) => {
    const output = Array.from({ length: M }, () => Array.from({ length: N }, () => 0));
    let answer = 0;
    
    // 1열부터 N열까지 순회
    for (let x = 0; x < N; x++) {
        // 1행부터 M행까지 순회
        for (let y = 0; y < M; y++) {
            let prevMaxOutput = 0;
            for (let dir = 0; dir < 3; dir++) {
                const ny = y + DY[dir];
                const nx = x + DX[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                prevMaxOutput = Math.max(prevMaxOutput, output[ny][nx]);
            }
            output[y][x] = prevMaxOutput + weight[y][x];
            answer = Math.max(answer, prevMaxOutput);
        }
    }
    console.log(answer);
}