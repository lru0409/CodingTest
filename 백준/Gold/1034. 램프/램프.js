const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
    input.push(line);
}).on("close", () => {
    const [N, M] = input.shift().split(" ").map(Number);
    const K = parseInt(input.pop());
    solution(N, M, K, input);
})

function solution (N, M, K, table) {

    // 행의 패턴마다 { 행의 패턴: 총 개수 }를 patternCounts에 저장한다.
    const patternCounts = {};
    table.forEach((row) => {
        patternCounts[row] = patternCounts[row] ? patternCounts[row] + 1 : 1;
    });

    // patternCounts를 순회하면서 다음을 확인해 정답을 갱신한다.
        // 0의 개수가 K 이하인가
        // K % 0의 개수가 짝수인가
        // 총 개수가 가장 max 값인가
    let answer = 0;
    Object.entries(patternCounts).forEach(([pattern, count]) => {
        const zeroCount = [...pattern].reduce((acc, c) => c === '0' ? acc + 1 : acc, 0);
        if (zeroCount > K) return;
        if ((K - zeroCount) % 2 !== 0) return;
        answer = Math.max(answer, count); 
    });
    console.log(answer);
}