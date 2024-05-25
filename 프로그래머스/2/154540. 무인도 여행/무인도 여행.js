function solution(maps) {
    
    const visited = new Array(maps.length).fill(null).map(() => new Array(maps[0].length).fill(false));
    
    const dy = [-1, 1, 0, 0];
    const dx = [0, 0, -1, 1];
    const BFS = function(startY, startX) {
        let food = 0;
        const queue = [ [startY, startX] ];
        visited[startY][startX] = true;
        
        while (queue.length) {
            let [cy, cx] = queue.shift();
            food += parseInt(maps[cy][cx]);
            for(let i = 0; i < 4; i++) {
                let ny = cy + dy[i];
                let nx = cx + dx[i];
                if (ny < 0 || nx < 0 || ny >= maps.length || nx >= maps[0].length)
                    continue;
                if (maps[ny][nx] === 'X' || visited[ny][nx] === true)
                    continue;
                visited[ny][nx] = true;
                queue.push([ny, nx]);
            }
        }
        return food;
    }
    
    var answer = [];
    for(let i = 0; i < maps.length; i++) {
        for(let j = 0; j < maps[i].length; j++) {
            if (maps[i][j] !== 'X' && visited[i][j] === false) {
                answer.push(BFS(i, j));   
            }
        }
    }
    
    if (answer.length === 0) {
        return [-1];
    }
    return answer.sort((a, b) => a - b);
}