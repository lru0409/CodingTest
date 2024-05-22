function solution(maps) {

    const dy = [-1, 1, 0, 0];
    const dx = [0, 0, -1, 1];
    
    const BFS = function(start, target) {
        const queue = [ [...start, 0] ];
        const visited = new Array(maps.length).fill(null).map(() => new Array(maps[0].length, false));
        visited[start[0]][start[1]] = true;
        
        while (queue.length) {
            let [currentY, currnetX, currentDist] = queue.shift();
            
            for(let i = 0; i < 4; i++) {
                let nextY = currentY + dy[i];
                let nextX = currnetX + dx[i];
                if (nextY < 0 || nextX < 0 || 
                    nextY >= maps.length || nextX >= maps[0].length ||
                    maps[nextY][nextX] === 'X' ||
                    visited[nextY][nextX] === true)
                {
                    continue;
                }
                if (nextY === target[0] && nextX === target[1])
                    return currentDist + 1;
                visited[nextY][nextX] = true;
                queue.push([nextY, nextX, currentDist + 1]);
            }
        }
        return -1;
    }

    // 맵을 순회하며 시작 시점, 레버, 문 위치 찾기
    const positions = { start: null, lever: null, exit: null };

    for(let i = 0; i < maps.length; i++) {
        for(let j = 0; j < maps[i].length; j++) {
            if (maps[i][j] === 'S') {
                positions.start = [i, j];
            } else if (maps[i][j] === 'L') {
                positions.lever = [i, j];
            } else if (maps[i][j] === 'E') {
                positions.exit = [i, j];
            }
        }
    }
    
    let startToLever = BFS(positions.start, positions.lever); // 시작 위치 -> 레버
    let leverToExit = BFS(positions.lever, positions.exit); // 레버 -> 탈출 위치
    if (startToLever === -1 || leverToExit === -1)
        return -1;
    return startToLever + leverToExit;
}