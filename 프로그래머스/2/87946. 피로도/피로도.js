function solution(k, dungeons) {
    
    const order = new Array(dungeons.length);
    const visited = new Array(dungeons.length).fill(false);
    let maxCount = 0;
    
    const checkCase = function() {
        let health = k;
        let count = 0;
        for (dungeon of order) {
            if (health < dungeon[0])
                break;
            health -= dungeon[1];
            count++;
        }
        maxCount = Math.max(maxCount, count);
    }
    
    const searchAllCase = function(depth) {
        if (depth === dungeons.length) {
            checkCase();
            return;
        }
        
        for (let i = 0; i < dungeons.length; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            order[depth] = dungeons[i];
            searchAllCase(depth + 1);
            visited[i] = false;
        }
    }
    
    searchAllCase(0);
    
    return maxCount;
}