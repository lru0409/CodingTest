const readline = require("readline");
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let input;

rl.on('line', (line) => {
    input = line;
}).on('close', () => {
    solution(parseInt(input));
});

const solution = (N) => {
    let countB = 0;
    let countS = 0;
    let head = '';
    let tail = '';

    const isPrime = new Array(N + 1).fill(true);
    isPrime[0] = isPrime[1] = false;
    for (let i = 2; i <= N; i++) {
        let multi = 2;
        while (i * multi <= N) {
            isPrime[i * multi++] = false;
        }
    }

    for (let i = 1; i <= N; i++) {
        if (!isPrime[i]) {
            tail = 'B';
            if (head === '') head = 'B';
            countB++;
            continue;
        }
        if (tail === 'B') {
            countB--;
            countS++;
            if (i === 2) {
                head = 'S';
            }
        }
        tail = 'S';
        countS++;
        const tempHead = head;
        head = tail;
        tail = tempHead;
    }
    console.log(countB, countS);
}

