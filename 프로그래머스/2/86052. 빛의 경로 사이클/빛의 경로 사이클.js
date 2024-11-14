function solution(grid) {    
    const Y = grid.length;
    const X = grid[0].length;
    const DY = [-1, 0, 1, 0];
    const DX = [0, 1, 0, -1];
    
    const visited = new Array(Y).fill(null).map(() => Array(X).fill(null).map(() => Array(4)));
    
    const DIR_MAP = { L: 3, R: 1, S: 0 };
    
    const processCycle = (y, x, d) => {
        let len = 0;
        let cy = y, cx = x, cd = d;
        while (true) {
            cy += DY[cd];
            cx += DX[cd];
            if (cy < 0) cy = Y - 1;
            if (cy >= Y) cy = 0;
            if (cx < 0) cx = X - 1;
            if (cx >= X) cx = 0;
            cd = (cd + DIR_MAP[grid[cy][cx]]) % 4;
            len++;
            if (visited[cy][cx][cd]) {
                if (cy === y && cx === x && cd === d) answer.push(len);
                break;
            }
            visited[cy][cx][cd] = true;
        }
    }
    
    const answer = [];
    // 모든 좌표에서 동서남북으로 시작해본다.
    for (let y = 0; y < Y; y++) {
        for (let x = 0; x < X; x++) {
            for (let d = 0; d < 4; d++) {
                if (visited[y][x][d]) continue;
                visited[y][x][d] = true;
                processCycle(y, x, d);
            }
        }
    }
    
    return answer.sort((a, b) => a - b);
}