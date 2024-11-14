function solution(grid) {    
    const Y = grid.length;
    const X = grid[0].length;
    const DY = [-1, 0, 1, 0];
    const DX = [0, 1, 0, -1];
    
    const visited = new Array(Y).fill(null).map(() => Array(X).fill(null).map(() => Array(4)));
    
    const DIR_MAP = { L: 3, R: 1, S: 0 };
    
    const processCycle = (y, x, d) => {
        let len = 0;
        while (true) {
            // 이동시키고 방향 바꾸기
            y += DY[d];
            x += DX[d];
            if (y < 0) y = Y - 1;
            if (y >= Y) y = 0;
            if (x < 0) x = X - 1;
            if (x >= X) x = 0;
            d = (d + DIR_MAP[grid[y][x]]) % 4;
            len++;
            if (visited[y][x][d]) break;
            visited[y][x][d] = true;
        }
        return len;
    }
    
    const answer = [];
    // 모든 좌표에서 동서남북으로 시작해본다.
    for (let y = 0; y < Y; y++) {
        for (let x = 0; x < X; x++) {
            for (let d = 0; d < 4; d++) {
                if (visited[y][x][d]) continue;
                visited[y][x][d] = true;
                answer.push(processCycle(y, x, d));
            }
        }
    }
    
    return answer.sort((a, b) => a - b);
}