function solution(topping) {
    
    const mapA = new Map();
    const mapB = new Map();
    let countA = 1;
    let countB = 0;
    
    mapA.set(topping[0], 1);
    for (let i = 1; i < topping.length; i++) {
        if (mapB.has(topping[i])) {
            mapB.set(topping[i], mapB.get(topping[i]) + 1);
        } else {
            countB++;
            mapB.set(topping[i], 1);
        }
    }
    
    let answer = 0;
    for (let i = 1; i < topping.length - 1; i++) {
        if (mapA.has(topping[i])) {
            mapA.set(topping[i], mapA.get(topping[i]) + 1);
        } else {
            countA++;
            mapA.set(topping[i], 1);
        }
        if (mapB.get(topping[i]) - 1 === 0) {
            mapB.delete(topping[i]);
            countB--;
        } else {
            mapB.set(topping[i], mapB.get(topping[i]) - 1);
        }
        
        if (countA === countB)
            answer++;
    }
    
    return answer;
}