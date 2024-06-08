function solution(a, b, n) {
    
    let answer = 0;
    
    while (n >= a) {
        const give_count = n - (n % a);
        n -= give_count;
        n += (give_count / a) * b;
        answer += (give_count / a) * b;
    }

    return answer;
}