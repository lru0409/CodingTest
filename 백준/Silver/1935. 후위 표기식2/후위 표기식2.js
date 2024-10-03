const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = parseInt(input.shift());
    const expression = input.shift().split("");
    const numbers = input.map(Number);
    solution(N, expression, numbers);
})

const solution = (N, expression, numbers) => {
    const alphaMap = {};
    let numbersIdx = 0;
    for (let expIdx = 0; expIdx < expression.length; expIdx++) {
        if (expression[expIdx] === '*' ||   
            expression[expIdx] === '+' || 
            expression[expIdx] === '/' || 
            expression[expIdx] === '-') {
            continue;
        }
        if (!alphaMap.hasOwnProperty(expression[expIdx])) {
            alphaMap[expression[expIdx]] = numbers[numbersIdx++];
        }
        expression[expIdx] = alphaMap[expression[expIdx]];
    }

    const stack = [];
    for (let i = 0; i < expression.length; i++) {
        if (expression[i] === '*' ||   
            expression[i] === '+' || 
            expression[i] === '/' || 
            expression[i] === '-') {
            const a = stack.pop();
            const b = stack.pop();
            switch (expression[i]) {
                case '*':
                    stack.push(a * b);
                    continue;
                case '+':
                    stack.push(a + b);
                    continue;
                case '/':
                    stack.push(b / a);
                    continue;
                case '-':
                    stack.push(b - a);
                    continue;
            }
        } else {
            stack.push(expression[i]);
        }
    }
    console.log(stack.pop().toFixed(2));
}