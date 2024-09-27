const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
    const N = parseInt(input.shift()); 
    const metarials = input.map((line) => {
        const [S, B] = line.split(" ").map(Number);
        return { S, B };
    });
    solution(N, metarials);
});

let minDiff = Infinity;

function calculate(metarials) {
    let sSum = metarials.reduce((sum, { S }) => sum * S, 1);
    let bSum = metarials.reduce((sum, { B }) => sum + B, 0);
    minDiff = Math.min(minDiff, Math.abs(sSum - bSum));
}

function combination(selected, count, metarials, next) {
    if (selected.length === count) {
        calculate(selected);
        return;
    }
    for (let i = next; i < metarials.length; i++) {
        selected.push(metarials[i]);
        combination(selected, count, metarials, i + 1);
        selected.pop();
    }
}

function solution(N, metarials) {
    for (let i = 1; i <= N; i++) {
        combination([], i, metarials, 0);
    }
    console.log(minDiff);
}