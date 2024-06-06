function solution(arrayA, arrayB) {
    
    const getGCD = function(array) {
        const min = array.reduce((accumulator, currentValue) => {
            return Math.min(accumulator, currentValue);
        });
        let gcd;
        for (gcd = min; gcd >= 1; gcd--) {
            if (min % gcd !== 0)
                continue;
            if (array.every((num) => num % gcd === 0))
                break;
        }
        return gcd;
    }
    
    let answer = 0;
    
    const gcdA = getGCD(arrayA);
    if (gcdA !== 1) {
        if (!arrayB.some(num => num % gcdA === 0))
            answer = gcdA;
    }
    const gcdB = getGCD(arrayB);
    if (gcdB !== 1) {
        if (!arrayA.some(num => num % gcdB === 0))
            answer = Math.max(answer, gcdB);
    }

    return answer;
}