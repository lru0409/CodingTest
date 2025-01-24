const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin, ouput: process.stdout,
});

const input = [];
rl.on("line", (line) => {
    input.push(line);
}).on("close", (close) => {
    const [C, N] = input[0].split(" ").map(Number);
    const costPerCustomer = {};
    for (let i = 1; i <= N; i++) {
        const [cost, customer] = input[i].split(" ").map(Number);
        if (costPerCustomer[customer]) {
            costPerCustomer[customer] = Math.min(costPerCustomer[customer], cost);
        } else {
            costPerCustomer[customer] = cost;
        }
    }
    solution(C, costPerCustomer);
})

const solution = (C, costPerCustomer) => {
    const dp = new Array(C + 101).fill(Infinity); // index 고객 수, value 비용
    for (let i = 1; i <= C + 100; i++) {
        dp[i] = costPerCustomer[i] || Infinity;
        for (let j = 1; j < i; j++) {
            dp[i] = Math.min(dp[i], dp[j] + dp[i - j]);
        }
    }
    let answer = Infinity;
    for (let i = C; i <= C + 100; i++) {
        answer = Math.min(answer, dp[i]);
    }
    console.log(answer);
}