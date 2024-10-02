const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = parseInt(input[0]); 
    const [r1, c1, r2, c2] = input[1].split(" ").map(Number);
    const start = [r1, c1];
    const target = { r: r2, c: c2};
    solution(N, start, target);
});

const DY = [-2, -2, 0, 0, 2, 2];
const DX = [-1, 1, -2, 2, -1, 1];

function solution(N, start, target) {
    const queue = [ [...start, 0] ];
    const visited = new Array(N).fill(null).map(() => Array(N).fill(false));

    while (queue.length) {
        const [cy, cx, count] = queue.shift();
        if (cy === target.r && cx === target.c) {
            console.log(count);
            return;
        }

        for (let i = 0; i < 6; i++) {
            const ny = cy + DY[i];
            const nx = cx + DX[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            queue.push([ny, nx, count + 1]);
        }
    }
    console.log(-1);
}