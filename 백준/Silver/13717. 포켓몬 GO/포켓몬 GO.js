const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = input.shift();
  const mons = [];
  for (let i = 0; i < N; i++) {
    const [k, m] = input[i * 2 + 1].split(" ").map(Number);
    const mon = { name: input[i * 2], k, m };
    mons.push(mon);
  }
  solution(N, mons);
});

let totalEvolutionCount = 0;
let maxEvolutionCount = 0;
let maxEvolutionMon = null;

const solution = (N, mons) => {
  const getEvolutionCount = (k, m) => {
    let evolutionCount = 0;
    while (true) {
      let count = Math.floor(m / k);
      if (count === 0) return evolutionCount;
      evolutionCount += count;
      m = (m % k) + count * 2;
    }
  };

  for (mon of mons) {
    const evolutionCount = getEvolutionCount(mon.k, mon.m);
    totalEvolutionCount += evolutionCount;
    if (maxEvolutionCount < evolutionCount) {
      maxEvolutionCount = evolutionCount;
      maxEvolutionMon = mon.name;
    }
    if (maxEvolutionCount === evolutionCount && !maxEvolutionMon)
      maxEvolutionMon = mon.name;
  }
  console.log(totalEvolutionCount);
  console.log(maxEvolutionMon);
};
