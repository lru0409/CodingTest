function solution(expression) {
    const parsed = [];
    let numberStart;
    for (let i = 0; i < expression.length; i++) {
        numberStart = i;
        while (i < expression.length && !isNaN(Number(expression[i]))) i++;
        parsed.push(Number(expression.slice(numberStart, i)));
        if (i < expression.length) parsed.push(expression[i]);
    }
    
    const operators = ['+', '-', '*'];
    const calculate = (p) => {
        let calculationArr = parsed.slice();
        for (let i = 0; i < p.length; i++) {
            const operator = operators[p[i]];
            for (let j = 0; j < calculationArr.length; j++) {
                if (calculationArr[j] !== operator) continue;
                // operator 연산자를 만나면 앞과 뒤의 숫자 연산
                const num1 = calculationArr[j - 1];
                const num2 = calculationArr[j + 1];
                let result;
                if (operator === '+') result = num1 + num2;
                else if (operator === '-') result = num1 - num2;
                else result = num1 * num2;
                calculationArr.splice(j - 1, 3, result);
                j--;
            }
        }
        return calculationArr[0];
    }
    
    let answer = 0;
    const permutation = (p, visited) => { // 연산문자의 수열
        if (p.length === 3) {
            const result = calculate(p);
            answer = Math.max(answer, Math.abs(result));
            return;
        }
        for (let i = 0; i < 3; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            p.push(i);
            permutation(p, visited);
            p.pop();
            visited[i] = false;
        }
    }
    permutation([], new Array(3).fill(false));
    return answer;
}
