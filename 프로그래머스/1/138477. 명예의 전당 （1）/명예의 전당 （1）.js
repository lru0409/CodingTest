function solution(k, score) {
    
    const lank = [];
    const answer = [];
    
    for (let i = 0; i < score.length; i++) {
        lank.push(score[i]);
        lank.sort((a, b) => b - a);
        if (lank.length > k) {
            lank.pop();
        }
        answer.push(lank[lank.length - 1]);
    }
    
    return answer;
}