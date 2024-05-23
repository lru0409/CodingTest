function solution(s, skip, index) {
    
    let skipMap = new Map();
    for(let i = 0; i < 26; i++) {
        skipMap.set(i, false);
    }
    for(char of skip) {
        skipMap.set(char.charCodeAt(0) - 97, true);
    }
    
    let answer = '';
    for(let i = 0; i < s.length; i++) {
        let key = s.charCodeAt(i) - 97;
        let count = 0;
        while (true) {
            if (skipMap.get(key) === true) {
                key = (key + 1) % 26;
                continue;
            }
            if (index <= count)
                break;
            key = (key + 1) % 26;
            count++;
        }
        answer += String.fromCharCode(key + 97);
    }
    
    return answer;
}