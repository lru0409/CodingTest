function solution(n, left, right) {
    
    const array = [];
    
    for (let i = left; i <= right; i++) {
        const row = Math.floor(i / n) + 1;
        const col = (i % n) + 1;
        array.push(Math.max(row, col));
    }
    
    return array;
}