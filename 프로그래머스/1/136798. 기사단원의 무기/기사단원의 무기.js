function solution(number, limit, power) {
    
    let answer = 0;
    
    for (let i = 1; i <= number; i++) {
        let count = 0;
        for (let j = 1; j <= Math.sqrt(i); j++) {
            if (i % j === 0) {
                count += 1;
                if (i / j !== j) count += 1;
            }
        }
        if (limit < count)
            answer += power;
        else
            answer += count;
    }

    return answer;
}