function solution(board) {
    let startY, startX;
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[i].length; j++) {
            if (board[i][j] == 'R') {
                startY = i;
                startX = j;
            }
        }
    }
    let answer = BFS(board, startY, startX);
    return answer;
}

const dy = [ -1, 1, 0, 0 ];
const dx = [ 0, 0, -1, 1 ];

function BFS(board, startY, startX) {
    let queue = [];
    queue.push([startY, startX, 0]);
    let visited = [];
    for(let i = 0; i < board.length; i++) {
        visited.push([]);
        for(let j = 0; j < board[i].length; j++) {
            visited[i].push(false);
        }
    }
    visited[startY][startX] = true;
    
    while (queue.length > 0) {
        let [cy, cx, move_cnt] = queue[0];
        queue.shift();
        
        for(let i = 0; i < 4; i++) {
            let [ny, nx] = [cy, cx];
            while (true) {
                if (ny + dy[i] < 0 || nx + dx[i] < 0)
                    break;
                if (board.length <= ny + dy[i] || board[0].length <= nx + dx[i])
                    break;
                if (board[ny + dy[i]][nx + dx[i]] === 'D')
                    break;
                ny += dy[i];
                nx += dx[i];
            }
            if (visited[ny][nx] === true)
                continue;
            if (board[ny][nx] === 'G')
                return move_cnt + 1;
            visited[ny][nx] = true;
            queue.push([ny, nx, move_cnt + 1]);
        }
    }
    return -1;
}