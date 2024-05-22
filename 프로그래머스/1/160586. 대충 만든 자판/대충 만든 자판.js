function solution(keymap, targets) {
    
    const max = 101;
    const alphaCount = new Array(26).fill(max);
    
    for(key of keymap) {
        for(let i = 0; i < key.length; i++) {
            let index = key.charCodeAt(i) - 65;
            alphaCount[index] = Math.min(alphaCount[index], i + 1);
        }
    }
    
    let answer = [];
    for(target of targets) {
        let totalCnt = 0;
        let i;
        for(i = 0; i < target.length; i++) {
            let charCnt = alphaCount[target.charCodeAt(i) - 65];
            if (charCnt == max)
                break;
            totalCnt += charCnt;
        }
        if (i < target.length)
            answer.push(-1);
        else
            answer.push(totalCnt);
    }
    
    return answer;
}