function solution(s) {
    
    let answer = 0;

    for (let i = 0; i < s.length; i++) {
        let x = s[i];
        const count = [1, 0]; // x와 x가 아닌 글자의 등장 횟수
        while (i < s.length && count[0] != count[1]) {
            i++;
            if (s[i] === x) count[0]++;
            else count[1]++;
        }
        answer += 1;
    }
    
    return answer;
}