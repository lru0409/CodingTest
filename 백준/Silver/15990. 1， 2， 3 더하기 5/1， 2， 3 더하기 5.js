const readline = require("readline");
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    input.shift();
    solution(input.map(Number));
});

const solution = (numbers) => {
    const max = Math.max(...numbers);
    // DP[i][j] : i를 만들되 j로 끝나는 경우의 수
    const DP = new Array(max + 1).fill(null).map(() => Array(4).fill(0));
    DP[1][1] = 1; // (1)
    DP[2][2] = 1; // (2)
    DP[3][1] = 1; // (2 1)
    DP[3][2] = 1; // (1 2)
    DP[3][3] = 1; // (3)

    for (let i = 4; i <= max; i++) {
        // (i - 1)에서 1을 더하거나
        // (i - 2)에서 2를 더하거나
        // (i - 3)에서 3을 더하거나
        for (let j = 1; j <= 3; j++) {
            // 이전 DP 값에서 j는 제외
            const sum = DP[i - j][1] + DP[i - j][2] + DP[i - j][3] - DP[i - j][j];
            DP[i][j] = sum % 1000000009;
        }
    }

    numbers.forEach((number) => {
        console.log((DP[number][1] + DP[number][2] + DP[number][3]) % 1000000009);
    });
}