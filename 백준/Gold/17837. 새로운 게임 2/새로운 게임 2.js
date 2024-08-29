const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

const WHITE = 0;
const RED = 1;
const BLUE = 2;

const DY = [0, 0, -1, 1];
const DX = [1, -1, 0, 0];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [N, K] = input.shift().split(" ").map(Number);
  const map = input.slice(0, N).map((line) => line.split(" ").map(Number));
  const horses = input.slice(N).map((line, id) => {
    const [r, c, d] = line.split(" ").map(Number);
    return { id, r: r - 1, c: c - 1, d: d - 1 };
  });
  solution(N, K, map, horses);
});

function solution(N, K, map, horses) {
  let turn = 1;
  let isEnd = false;
  map = map.map((row) => {
    return row.map((color) => {
      return { color, horses: [] };
    });
  });
  horses.forEach((horse) => {
    map[horse.r][horse.c].horses.push(horse);
  });

  // 말이 4개 이상 쌓여있는지 확인
  const fourStacks = map.some((row) => {
    return row.some((square) => {
      return 4 <= square.horses.length;
    });
  });
  if (fourStacks) {
    console.log(0);
    return;
  }

  while (turn < 1000 && !isEnd) {
    // 말 이동
    for (const horse of horses) {
      const { r, c, d } = horse;
      let nr = r + DY[d];
      let nc = c + DX[d];
      if (outOfMap(nr, nc, N) || map[nr][nc].color === BLUE) {
        horse.d += d % 2 === 0 ? 1 : -1; // 방향 바꾸기
        nr = r + DY[horse.d];
        nc = c + DX[horse.d];
        // 이동하려는 칸이 맵을 벗어나지 않고 파란칸이 아니면 이동
        if (outOfMap(nr, nc, N) || map[nr][nc].color === BLUE) continue;
      }
      moveHorse(map, horse, nr, nc, map[nr][nc].color === RED);
      if (4 <= map[nr][nc].horses.length) {
        console.log(turn);
        return;
      }
    }
    turn++;
  }

  console.log(-1);
}

function moveHorse(map, horse, nr, nc, reverse) {
  const moveHorses = [];
  while (true) {
    const h = map[horse.r][horse.c].horses.pop();
    moveHorses.push(h);
    if (h.id === horse.id) break;
  }
  if (!reverse) moveHorses.reverse();
  moveHorses.forEach((horse) => {
    map[nr][nc].horses.push(horse);
    horse.r = nr;
    horse.c = nc;
  });
}

function outOfMap(r, c, N) {
  return r < 0 || c < 0 || r >= N || c >= N;
}
