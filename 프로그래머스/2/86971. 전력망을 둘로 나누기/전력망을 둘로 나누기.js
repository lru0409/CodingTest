function solution(n, wires) {    
    // 인접 리스트 생성
    const tree = new Array(101).fill(null).map(() => []);
    wires.forEach(([v1, v2]) => {
        tree[v1].push(v2);
        tree[v2].push(v1);
    });
    
    // start부터 돌면서 연결된 노드 개수 세어 반환 (except 노드로는 가지 않음)
    const getNodeCount = (start, except) => {
        const queue = [ start ];
        const visited = new Array(101).fill(false);
        visited[start] = true;
        let count = 1;
        while (queue.length) {
            const cur = queue.shift();
            for (let i = 0; i < tree[cur].length; i++) {
                if (visited[tree[cur][i]]) continue;
                if (tree[cur][i] === except) continue;
                visited[tree[cur][i]] = true;
                count++;
                queue.push(tree[cur][i]);
            }
        }
        return count;
    }
    
    let answer = Infinity;
    // 일일이 다 끊어본다
    tree.forEach((nexts, current) => {
        nexts.forEach((next) => {
            const cnt1 = getNodeCount(current, next);
            const cnt2 = getNodeCount(next, current);
            answer = Math.min(answer, Math.abs(cnt1 - cnt2));
        });
    });
    
    return answer;
}