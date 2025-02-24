const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
    input.push(line);
}).on("close", () => {
    solution(input.map((line) => {
        const parts = line.split(" ");
        if (parts[0] === 'Query') return { type: parts[0], T: Number(parts[1])};
        return { type: parts[0], T: Number(parts[1]), N: Number(parts[2])};
    }));
});

const solution = (input) => {
    input.sort((a, b) => {
        if (a.T !== b.T) return a.T - b.T;
        if (a.type !== b.type) return a.type === "Query" ? 1 : -1;
        return 0;
    });

    const foods = [];

    for (let i = 0; i < input.length; i++) {
        if (input[i].type === "Query") {
            // T 시간의 안전 거리 구해서 출력하기
            let safeDist = 0;
            for (const {type, T, N} of foods) {
                const timePassed = input[i].T - T;
                if (type === "Chocolate") {
                    safeDist += Math.max(0, 8*N - timePassed/12);
                } else {
                    safeDist += Math.max(0, 2*N - timePassed*timePassed/79);
                }
            }
            safeDist = Math.max(safeDist, 1);
            console.log(input[i].T, safeDist.toFixed(1));
            continue;
        }
        foods.push(input[i]);
    }
}