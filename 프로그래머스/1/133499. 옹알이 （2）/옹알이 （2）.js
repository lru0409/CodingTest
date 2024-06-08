function solution(babbling) {
    
    const anounce = ['aya', 'ye', 'woo', 'ma'];
    let answer = 0;
    
    for (const str of babbling) {
        let index = 0;
        let prev = '';
        while (index < str.length) {
            const exist = anounce.find((a) => {
                if (str.substr(index, a.length) === a && a !== prev)
                    return true;
                return false;
            })
            if (exist === undefined)
                break;
            prev = exist;
            index += exist.length;
        }
        if (index === str.length)
            answer++;
    }
    
    return answer;
}