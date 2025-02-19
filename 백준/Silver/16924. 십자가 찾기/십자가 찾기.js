const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", (close) => {
    const [N, M] = input.shift().split(" ").map(Number);
    solution(N, M, input.map((line) => line.split("")));
});

const DY = [0, 0, 1, -1];
const DX = [1, -1, 0, 0];

const solution = (N, M, board) => {
    const visited = new Array(N).fill(null).map(() => new Array(M).fill(false));
    const cross = []; // 행, 열, 크기

    for (let y = 1; y < N - 1; y++) {
        for (let x = 1; x < M - 1; x++) {
            // 현재 y, x 위치에서 최대 크기 십자가 만들기
            if (board[y][x] !== "*") continue;
            // 동서남북 방향으로 * 개수 세기
            const count = new Array(4).fill(0);
            for (let dir = 0; dir < 4; dir++) {
                let ny = y, nx = x;
                while (true) {
                    ny += DY[dir];
                    nx += DX[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
                    if (board[ny][nx] !== "*") break;
                    count[dir]++;
                }
            }
            const size = Math.min(...count); // 만들 수 있는 최대 크기의 십자가 크기
            if (size === 0) continue;
            // size 만큼 마킹하기
            visited[y][x] = true;
            for (let dir = 0; dir < 4; dir++) {
                for (let count = 1; count <= size; count++) {
                    visited[y + (count * DY[dir])][x + (count * DX[dir])] = true;
                }
            }
            cross.push([y + 1, x + 1, size]);
        }
    }
    
    // * 중 마킹된 곳이 없으면 -1
    for (let y = 0; y < N; y++) {
        for (let x = 0; x < N; x++) {
            if (board[y][x] === "*" && !visited[y][x]) {
                console.log(-1);
                return;
            }
        }
    }
    console.log(cross.length);
    console.log(cross.map((el) => el.join(" ")).join("\n"));
}


// 가장자리 제외 모든 위치를 돌면서
    // - 만들 수 있는 최고 크기 십자가 구하기
    // - 만든 십자가에 포함된 곳은 마킹하기
// 다 돌았을 때 * 중 마킹된 곳이 없으면 -1