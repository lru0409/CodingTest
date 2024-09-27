const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
    const N = parseInt(input[0]);
    const num = parseInt(input[1]);
    solution(N, num);
});

const UP = 0;
const RIGHT = 1;
const DOWN = 2;
const LEFT = 3;

const DY = [-1, 0, 1, 0];
const DX = [0, 1, 0, -1];

function solution(N, targetNum) {
    const result = new Array(N).fill(null).map(() => Array(N).fill(0));
    let y = Math.floor(N / 2);
    let x = Math.floor(N / 2);
    let num = 1;
    let dist = 1;
    let distCount = 0;
    let dir = UP;
    let targetPos;
    let end = false;

    if (num === targetNum) {
        targetPos = [y + 1, x + 1];
    }
    result[y][x] = num++;

    while (!end) {
        for (let i = 0; i < dist; i++) {
            y += DY[dir];
            x += DX[dir];
            if (y < 0) {
                end = true;
                break;
            }
            if (num === targetNum) {
                targetPos = [y + 1, x + 1];
            }
            result[y][x] = num++;
        }
        dir = (dir + 1) % 4;
        distCount++;
        if (distCount === 2) {
            dist++;
            distCount = 0;
        }
    }

    console.log(result.map((row) => row.join(' ')).join('\n'));
    console.log(targetPos.join(' '));

}