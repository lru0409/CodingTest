function solution(t, p) {
    
    const pLen = p.length;
    let answer = 0;
    
    for (let i = 0; i <= t.length - pLen; i++)
    {
        let partStr = t.substr(i, pLen);
        if (partStr <= p)
            answer++;
    }
    
    return answer;
}