const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
    const lineTrimmed = line.trim();
    if (0 < lineTrimmed.length) input.push(lineTrimmed);
}).on("close", () => {
    const T = Number(input[0]);
    const cases = [];
    for (let i = 1; i <= T; i++) {
        const N = Number(input[i * 2 - 1]);
        const arrivals = input[i * 2].split(" ").map(Number);
        cases.push({ N, arrivals });
    }
    solution(cases);
});

function solution(cases){
    for (const {N, arrivals} of cases) {
        const currents = new Array(N).fill(null).map((_, index) => index+1);
        let sadari = 0;
        while (arrivals.length) {
            // arrivals[0]번을 확정시키기
            const startIndex = currents.indexOf(arrivals[0]);
            sadari += startIndex;
            currents.splice(startIndex, 1);
            arrivals.shift();
        }
        console.log(sadari);
    }
}