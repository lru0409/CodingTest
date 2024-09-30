const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    solution(input);
});

const VALUE = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000 };
const SYMBOL = { 1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M' };

function arabiaToRoma(arabia) {
    let roma = '';
    const arabiaStr = arabia.toString();
    let digit =  Math.pow(10, arabiaStr.length - 1);

    while (arabia) {
        let curNum = Math.floor(arabia / digit);
        if (curNum === 4 || curNum === 9) {
            roma += `${SYMBOL[digit]}${SYMBOL[digit * (curNum === 4 ? 5 : 10)]}`;
        } else if (5 <= curNum) {
            arabia -= digit * 5;
            roma += SYMBOL[digit * 5];
            continue;
        } else {
            while (curNum--) roma += SYMBOL[digit];
        }
        arabia %= digit;
        digit /= 10;
    }
    return roma;
}

function romaToArabia(roma) {
    let arabia = 0;
    for (let i = 0; i < roma.length; i++) {
        if (i < roma.length - 1 && VALUE[roma[i]] < VALUE[roma[i + 1]]) {
            arabia += VALUE[roma[i + 1]] - VALUE[roma[i]];
            i++;
            continue;
        }
        arabia += VALUE[roma[i]];
    }
    return arabia;
}

function solution([romaA, romaB]) {
    const arabiaA = romaToArabia(romaA);
    const arabiaB = romaToArabia(romaB);
    console.log(arabiaA + arabiaB);
    console.log(arabiaToRoma(arabiaA + arabiaB));
}