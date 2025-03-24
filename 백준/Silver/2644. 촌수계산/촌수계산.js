const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const personCount = Number(input[0]);
    const [targetX, targetY] = input[1].split(" ").map(Number);
    const relationshipCount = Number(input[2]);
    const graph = new Array(personCount + 1).fill(null).map(() => new Array());
    for (let i = 3; i < 3 + relationshipCount; i++) {
        const [x, y] = input[i].split(" ").map(Number);
        graph[x].push(y);
        graph[y].push(x);
    }
    solution(personCount, targetX, targetY, graph);
});

function solution(personCount, targetX, targetY, graph) {
    const dfs = () => {
        const queue = [[targetX, 0]] // [현재 지나가는 사람, 촌수]
        const visited = new Array(personCount + 1).fill(false);
        visited[targetX] = true;
        while (queue.length) {
            const [person, count] = queue.shift();
            if (person === targetY) return count;
            for (let i = 0; i < graph[person].length; i++) {
                const next = graph[person][i];
                if (visited[next]) continue;
                visited[next] = true;
                queue.push([next, count + 1]);
            }
        }
        return -1;
    }
    console.log(dfs());
    return;
}