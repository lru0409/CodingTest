const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [N, Q] = input.shift().split(" ").map(Number);
  const board = input
    .slice(0, Math.pow(2, N))
    .map((line) => line.split(" ").map(Number));
  const step = input.pop().split(" ").map(Number);
  solution(N, Q, board, step);
});

function rotate(board) {
  const newBoard = board.map((row) => row.slice());
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      newBoard[j][board.length - i - 1] = board[i][j];
    }
  }
  return newBoard;
}

const DY = [-1, 1, 0, 0];
const DX = [0, 0, -1, 1];

function BFS(board, y, x, visited) {
  const queue = [[y, x]];
  visited[y][x] = true;
  let size = 0;

  while (queue.length) {
    const [cy, cx] = queue.shift();
    size++;

    for (let i = 0; i < 4; i++) {
      const ny = cy + DY[i];
      const nx = cx + DX[i];
      if (nx < 0 || ny < 0 || nx >= board.length || ny >= board.length)
        continue;
      if (visited[ny][nx] || board[ny][nx] === 0) continue;
      visited[ny][nx] = true;
      queue.push([ny, nx]);
    }
  }
  return size;
}

function solution(N, Q, board, step) {
  let index = 0;
  let length = Math.pow(2, N);
  let totalSize = length * length;

  while (index < Q) {
    // 마법 시전
    let rotateN = Math.pow(2, step[index]);
    for (let i = 0; i < totalSize / rotateN; i += rotateN) {
      const sy = Math.floor(i / length) * rotateN; // 시작 y
      const sx = i % length;
      piece = new Array(rotateN).fill(null).map(() => Array(rotateN));
      for (let y = 0; y < rotateN; y++) {
        for (let x = 0; x < rotateN; x++) {
          piece[y][x] = board[sy + y][sx + x];
        }
      }
      piece = rotate(piece);
      for (let y = 0; y < rotateN; y++) {
        for (let x = 0; x < rotateN; x++) {
          board[sy + y][sx + x] = piece[y][x];
        }
      }
    }
    // 얼음 줄어들기
    const meltPos = [];
    for (let y = 0; y < board.length; y++) {
      for (let x = 0; x < board[y].length; x++) {
        let count = 0;
        for (let i = 0; i < 4; i++) {
          const ny = y + DY[i];
          const nx = x + DX[i];
          if (ny < 0 || nx < 0 || ny >= board.length || nx >= board.length)
            continue;
          if (board[ny][nx] !== 0) count++;
        }
        if (count < 3) meltPos.push([y, x]);
      }
    }
    for (let i = 0; i < meltPos.length; i++) {
      const [y, x] = meltPos[i];
      board[y][x] = Math.max(0, board[y][x] - 1);
    }
    index++;
  }

  const sum = board.reduce((sum, row) => {
    return sum + row.reduce((sum, amount) => sum + amount, 0);
  }, 0);
  let maxSize = 0;
  const visited = new Array(board.length)
    .fill(null)
    .map(() => Array(board.length).fill(false));
  for (let y = 0; y < board.length; y++) {
    for (let x = 0; x < board[y].length; x++) {
      if (visited[y][x] || board[y][x] === 0) continue;
      const size = BFS(board, y, x, visited);
      maxSize = Math.max(maxSize, size);
    }
  }
  console.log(sum);
  console.log(maxSize);
}
