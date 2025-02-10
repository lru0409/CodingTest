const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

const columns = "ABCDEFGH";

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", (close) => {
  const [king, stone, N] = input.shift().split(" ");
  const kingPos = { r: 8 - parseInt(king[1]), c: columns.indexOf(king[0]) };
  const stonePos = { r: 8 - parseInt(stone[1]), c: columns.indexOf(stone[0]) };
  solution(N, kingPos, stonePos, input);
});

const DIR = {
  R: { r: 0, c: 1 },
  L: { r: 0, c: -1 },
  B: { r: 1, c: 0 },
  T: { r: -1, c: 0 },
  RT: { r: -1, c: 1 },
  LT: { r: -1, c: -1 },
  RB: { r: 1, c: 1 },
  LB: { r: 1, c: -1 },
};

const solution = (N, kingPos, stonePos, moves) => {
  for (let i = 0; i < N; i++) {
    const dir = DIR[moves[i]];
    // 킹 이동
    const nextKing = { r: kingPos.r + dir.r, c: kingPos.c + dir.c };
    if (nextKing.r < 0 || nextKing.c < 0 || nextKing.r >= 8 || nextKing.c >= 8)
      continue;
    // 킹이 이동한 자리에 돌이 있다면 돌 이동
    if (nextKing.r === stonePos.r && nextKing.c === stonePos.c) {
      const nextStone = { r: stonePos.r + dir.r, c: stonePos.c + dir.c };
      if (
        nextStone.r < 0 ||
        nextStone.c < 0 ||
        nextStone.r >= 8 ||
        nextStone.c >= 8
      )
        continue;
      stonePos = nextStone;
    }
    kingPos = nextKing;
  }

  console.log(`${columns[kingPos.c]}${8 - kingPos.r}`);
  console.log(`${columns[stonePos.c]}${8 - stonePos.r}`);
};
