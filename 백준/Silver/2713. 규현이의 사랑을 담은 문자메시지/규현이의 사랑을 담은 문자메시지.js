const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const T = Number(input[0]);
  const cases = [];
  for (let i = 1; i <= T; i++) {
    const [R, C, ...message] = input[i].split(" ");
    cases.push({ r: Number(R), c: Number(C), message: message.join(" ") });
  }
  solution(cases);
});

const DY = [0, 1, 0, -1];
const DX = [1, 0, -1, 0];
const DIR = { RIGHT: 0, DOWN: 1, LEFT: 2, UP: 3 };

function solution(cases) {
  for (const { r, c, message } of cases) {
    const matrix = Array.from({ length: r }, () => Array(c).fill(0));
    const visited = Array.from({ length: r }, () => Array(c).fill(false));
    let dir = DIR.RIGHT,
      y = 0,
      x = -1;
    for (let char of message) {
      const binary = (char === " " ? 0 : char.charCodeAt(0) - 64)
        .toString(2)
        .padStart(5, "0");
      for (const bit of binary) {
        let ny = y + DY[dir];
        let nx = x + DX[dir];
        // 벽을 만나거나 방문한 곳에 가면 방향을 바꾼다
        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) {
          dir = (dir + 1) % 4; // 방향 변경
          ny = y + DY[dir];
          nx = x + DX[dir];
        }
        visited[ny][nx] = true;
        matrix[ny][nx] = bit;
        y = ny;
        x = nx;
      }
    }

    console.log(matrix.flat().join("")); // 비밀 메시지 출력 (행 우선으로 읽기)
  }
}
