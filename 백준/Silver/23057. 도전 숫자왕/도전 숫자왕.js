const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = parseInt(input.shift());
    const numbers = input.shift().split(" ").map(Number);
    solution(N, numbers);
});

let makableCount = 0;

function combination(sum, count, totalCount, makable, numbers, next) {
    if (count === totalCount) {
        if (!makable.hasOwnProperty(sum)) {
            makable[sum] = true;
            makableCount++;
        }
        return;
    }
    for (let i = next; i < numbers.length; i++) {
        combination(sum + numbers[i], count + 1, totalCount, makable, numbers, i + 1);
    }
}

function solution(N, numbers) {
    const sum = numbers.reduce((sum, current) => sum + current);
    const makable = {};

    for (let i = 1; i <= N; i++) {
        combination(0, 0, i, makable, numbers, 0);
    }
    console.log(sum - makableCount);
}