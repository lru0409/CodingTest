function solution(x, y, n) {

    const queue = [ [y, 0] ]; // 숫자, 연산 횟수
    const visited = new Array(y).fill(false);
    
    const enqueueIfValid = function(next, op_cnt) {
        if (x <= next && visited[next] === false) {
            visited[next] = true;
            queue.push([next, op_cnt + 1]);
        }
    }

    while (queue.length) {
        const [num, op_cnt] = queue.shift();
        
        if (num === x)
            return op_cnt;
        
        enqueueIfValid(num - n, op_cnt);
        if (num % 2 === 0)
            enqueueIfValid(num / 2, op_cnt);
        if (num % 3 === 0)
            enqueueIfValid(num / 3, op_cnt);
    }

    return -1;
}