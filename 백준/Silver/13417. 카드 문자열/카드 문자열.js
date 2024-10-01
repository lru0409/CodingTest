const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    solution(input);
});

function solution(input) {
    let T = parseInt(input.shift());
    while (T--) {
        const N = parseInt(input.shift());
        const alphabets = input.shift().split(" ");
        let str = alphabets[0];
        for (let i = 1; i < alphabets.length; i++) {
            if (alphabets[i] <= str[0]) str = alphabets[i] + str;
            else str += alphabets[i];
        }
        console.log(str);
    }
}