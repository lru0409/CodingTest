const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = Number(input[0]);
    const M = Number(input[1]);
    const lines = [];
    for (let i = 2; i <= M + 1; i++) {
        const [computer1, computer2, cost] = input[i].split(" ").map(Number);
        lines.push({ computer1, computer2, cost });
    }
    solution(N, lines);
});

function solution(N, lines) {
    const graph = new Array(N + 1).fill(null).map(() => new Array());
    const checkConnection = (computer1, computer2) => {
        if (computer1 === computer2) return true;
        const queue = [computer1];
        const visited = new Array(N + 1).fill(false);
        visited[computer1] = true;
        while (queue.length) {
            const computer = queue.shift();
            for (const nextComputer of graph[computer]) {
                if (nextComputer === computer2) return true;
                if (visited[nextComputer]) continue;
                visited[nextComputer] = true;
                queue.push(nextComputer);
            }
        }
        return false;
    }

    let minCost = 0;
    lines.sort((a, b) => a.cost - b.cost); // 선을 비용 낮은 순으로 정렬
    for (const { computer1, computer2, cost } of lines) {
        // 현재 graph에서 computer1와 computer2가 연결되어있지 않다면 해당 라인을 추가
        const isConnected = checkConnection(computer1, computer2);
        if (isConnected) continue;
        graph[computer1].push(computer2);
        graph[computer2].push(computer1);
        minCost += cost;
    }
    console.log(minCost);
}