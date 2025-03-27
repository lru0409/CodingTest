const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = Number(input[0]);
    const towers = input[1].split(" ").map(Number);
    solution(N, towers);
});

function solution(N, towers) {
    const stack = []; // {number, height}
    const receiveTower = [];
    for (let i = 0; i < N; i++) {
        const tower = towers[i];
        // 현재 tower보다 낮은 tower들을 stack에서 제거
        while (stack.length && stack[stack.length - 1].height <= tower) stack.pop();
        receiveTower.push(stack.length === 0 ? 0 : stack[stack.length - 1].number);
        stack.push({number: i + 1, height: tower});
    }
    console.log(receiveTower.join(" "));
}