function solution(want, number, discount) {
    
    const setWantMap = function() {
        const wantMap = new Map();
        for (let i = 0; i < want.length; i++) {
            wantMap.set(want[i], number[i]);
        }
        return wantMap;
    }
    
    const possible = function(day) {

        const wantMap = setWantMap();

        for (let i = day; i < day + 10; i++) {
            if (!wantMap.has(discount[i]))
                return false;   
            const count = wantMap.get(discount[i]);
            if (count === 0)
                return false;   
            wantMap.set(discount[i], count - 1);
        }
        return true;
    }
    
    let answer = 0;
    for (let i = 0; i <= discount.length - 10; i++) {
        if (possible(i))
            answer++;
    }
    
    return answer;
}