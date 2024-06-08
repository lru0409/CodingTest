function solution(ingredient) {
    
    const stack = [];
    let answer = 0;
    
    for (let i = 0; i < ingredient.length; i++) {
        stack.push(ingredient[i]);
        if (stack.length >= 4) {
            if (stack[stack.length - 1] === 1 &&
                stack[stack.length - 2] === 3 &&
                stack[stack.length - 3] === 2 &&
                stack[stack.length - 4] === 1) {
                answer++;
                for (let j = 0; j < 4; j++)
                    stack.pop();
            }
        }
    }
    
    return answer;
}