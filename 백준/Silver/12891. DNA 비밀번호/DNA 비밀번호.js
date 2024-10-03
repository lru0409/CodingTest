const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];
rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [S, P] = input.shift().split(" ").map(Number);
    const dnaStr = input.shift();
    const minCounts = input.shift().split(" ").map(Number); 
    solution(S, P, dnaStr, minCounts);
})

const solution = (S, P, dnaStr, minCounts)  => {
    const [a, c, g, t] = minCounts;
    const minCountEntries = Object.entries({ A: a, C: c, G: g, T: t });

    const check = (countMap) => {
        for (const [key, count] of minCountEntries) {
            if (countMap[key] < count) return false;
        }
        return true;
    }

    const countMap = { A: 0, C: 0, G: 0, T: 0 };
    let result = 0;
    for (let i = 0; i < P; i++) {
        countMap[dnaStr[i]]++;
    }
    if (check(countMap)) result++;
    for (let i = 1; i < dnaStr.length - P + 1; i++) {
        countMap[dnaStr[i - 1]] -= 1;
        countMap[dnaStr[i + P - 1]] += 1;
        if (check(countMap)) result++;
    }
    console.log(result);
}