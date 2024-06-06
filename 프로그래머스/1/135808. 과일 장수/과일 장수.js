function solution(k, m, score) {
    
    score.sort((a, b) => b - a);
    
    let answer = 0;
    for (let i = 0; i < score.length; i++) {
        if ((i + 1) % m === 0) {
            answer += (score[i] * m);
        }
    }
    
    return answer;
}