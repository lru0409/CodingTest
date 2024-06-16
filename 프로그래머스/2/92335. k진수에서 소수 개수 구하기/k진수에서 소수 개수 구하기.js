function solution(n, k) {
    
    let changed = n.toString(k); // n을 k진수로 변환하기
    const candidates = changed.split('0').map(Number).filter((num) => num !== 0);
    
    const isPrime = function(number) {
        if (number === 1)
            return false;
        for (let i = 2; i <= Math.sqrt(number); i++) {
            if (number % i === 0)
                return false;
        }
        return true;
    }
    
    let answer = 0;
    candidates.forEach((number) => {
        if (isPrime(number))
            answer++;
    })
    
    return answer;
}