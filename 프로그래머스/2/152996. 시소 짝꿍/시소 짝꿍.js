function solution(weights) {

    let answer = 0;
    const weightCnt = new Map();
    
    for (weight of weights) {
        weightCnt.set(weight, (weightCnt.get(weight) || 0) + 1);
    }
    for (count of weightCnt.values()) {
        if (count >= 2)
            answer += (count * (count - 1)) / 2;
    }

    const multis = [[3, 2], [4, 2], [4, 3]];
    const checkPartner = function(w1, w2) {
        if (w1 === w2) return true;
        const [smaller, bigger] = w1 < w2 ? [w1, w2] : [w2, w1];
        return multis.some(([a, b]) => smaller * a === bigger * b);
    }
    
    const weightList = [...weightCnt.keys()];
    for (let i = 0; i < weightList.length; i++) {
        for (let j = i + 1; j < weightList.length; j++) {
            const w1 = weightList[i];
            const w2 = weightList[j];
            if (checkPartner(w1, w2) === true)
                answer += weightCnt.get(w1) * weightCnt.get(w2);
        }
    }
    
    return answer;
}