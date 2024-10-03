const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let input;
rl.on('line', (line) => {
    input = line;
}).on('close', () => {
    solution(parseInt(input));
})

const solution = (N) => {
    if (N % 2 === 0) {
        console.log("CY");
    } else {
        console.log("SK");
    }
}
