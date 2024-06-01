function solution(data, col, row_begin, row_end) {
    
    data.sort((a, b) => {
        if (a[col-1] != b[col-1])
            return a[col-1] - b[col-1];
        return b[0] - a[0];
    });
    
    const s = [];
    for (let i = row_begin; i <= row_end; i++) {
        let sum = 0;
        for (num of data[i-1]) {
            sum += num % i;
        }
        s.push(sum);
    }
    
    const answer = s.reduce((accumulator, currentValue) => accumulator ^ currentValue);
    return answer;
}
