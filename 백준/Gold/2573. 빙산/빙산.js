const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [N, M] = input.shift().split(" ").map(Number);
    const state = input.map((line) => line.split(" ").map(Number));
    solution(N, M, state);
});

const DY = [0, 0, 1, -1];
const DX = [1, -1, 0, 0];

function solution(N, M, prevState) {

    const bfs = (startY, startX, visited, state) => {
        const queue = [[startY, startX]];
        while (queue.length) {
            const [y, x] = queue.shift();
            for (let dir = 0; dir < 4; dir++) {
                const ny = y + DY[dir], nx = x + DX[dir];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (visited[ny][nx] || state[ny][nx] === 0) continue;
                visited[ny][nx] = true;
                queue.push([ny, nx]);
            }
        }
    }

    let year = 1;
    const state = new Array(N).fill(null).map(() => new Array(M).fill(0));
    while (true) {
        // 1년 지나기
        for (let y = 0; y < N; y++) {
            for (let x = 0; x < M; x++) {
                if (prevState[y][x] === 0) continue;
                let seaDirCount = 0; // 현재 위치에서 바다와 동서남북으로 접한 카운트를 구할 예정
                for (let dir = 0; dir < 4; dir++) {
                    const ny = y + DY[dir], nx = x + DX[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                    if (prevState[ny][nx] === 0) seaDirCount++;
                }
                state[y][x] = Math.max(0, prevState[y][x] - seaDirCount);
            }
        }
        prevState = state.map((row) => row.slice());
        // 빙산이 두 덩어리 이상으로 분리되었는지 확인
        const visited = new Array(N).fill(null).map(() => new Array(M).fill(false));
        let count = 0; // 덩어리 개수
        for (let y = 0; y < N; y++) {
            for (let x = 0; x < M; x++) {
                if (state[y][x] === 0 || visited[y][x]) continue;
                visited[y][x] = true;
                bfs(y, x, visited, state);
                count++;
            }
        }
        if (count >= 2) break;
        if (count === 0) {
            console.log(0);
            return;
        }
        year++; 
    }
    console.log(year);
}