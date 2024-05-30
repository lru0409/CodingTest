function solution(storey) {
    var answer = 0;

    while (storey) {
        const digit = storey % 10;

        if (digit <= 4) { // 4 이하면 무조건 빼는 게 좋음
            answer += digit;
        } else if (digit >= 6) { // 6 이상이면 무조건 더하는 게 좋음
            answer += 10 - digit;
            storey += 10;
        } else { // 5 이면
            if (Math.floor(storey % 100 / 10) <= 4) {
                answer += digit;
            } else {
                answer += 10 - digit;
                storey += 10;
            }
        }
        storey = Math.floor(storey / 10);
    }
    
    return answer;
}