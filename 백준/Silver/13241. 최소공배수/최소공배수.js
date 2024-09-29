const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let input;
rl.on('line', (line) => {
    input = line;
}).on('close', () => {
    const [A, B] = input.split(" ").map(Number);
    solution(A, B);
});

function solution(A, B) {
    const smaller = Math.min(A, B);
    let bigger = Math.max(A, B);

    let multiNum = 1;
    while (true) {
        const multiple = bigger * multiNum;
        if (multiple % smaller === 0) break;
        multiNum++;
    }
    console.log(bigger * multiNum);
}