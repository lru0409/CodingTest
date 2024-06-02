function solution(s) {
    
    let alpha = new Array(26).fill(-1);
    let answer = [];

    for (let i = 0; i < s.length; i++) {
        const index = s.charCodeAt(i) - 97;
        if (alpha[index] === -1) {
            answer.push(-1);
        } else {
            answer.push(i - alpha[index]);
        }
        alpha[index] = i;
    }
    
    return answer;
}