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
  const [N] = input[0].split(" ").map(Number);
  const strawberry = [];
  for (let i = 1; i < input.length; i++) {
    const [strawberryCount, startRabbit] = input[i].split(" ").map(Number);
    strawberry.push({ strawberryCount, startRabbit });
  }
  solution(N, strawberry);
});

// N 23
// K 4

// 0 0 0 0 0 0
// 0000 0000 0000 0000 0000 000

function solution(N, strawberry) {
  const K = Math.floor(Math.sqrt(N));
  const cupCount = N % K === 0 ? N / K : Math.floor(N / K) + 1;
  const cups = new Array(cupCount).fill(0);
  const lastBoxCount = N % K === 0 ? K : N % K;
  const boxes = new Array(cupCount).fill(null).map((_, index) => {
    return new Array(index === cupCount - 1 ? lastBoxCount : K).fill(0);
  });

  const getBoxCount = (cupIndex) => {
    return cupIndex === cupCount - 1 ? lastBoxCount : K;
  };

  for (let { strawberryCount, startRabbit } of strawberry) {
    // startRabbit부터 시작해서 strawberryCount개의 딸기를 나눠주기

    let matchCount = 0; // 이번에 성냥을 넣는 컵과 성냥갑의 총 성냥 개수

    // 성냥을 넣는 첫 블록
    let cupIndex = Math.floor((startRabbit - 1) / K);
    let boxIndex = (startRabbit - 1) % K;
    if (boxIndex !== 0) {
      // 첫 블록 중간부터 시작한다면 따로 처리
      while (boxIndex < getBoxCount(cupIndex) && 0 < strawberryCount) {
        boxes[cupIndex][boxIndex]++;
        matchCount += boxes[cupIndex][boxIndex];
        strawberryCount -= 1;
        boxIndex++;
      }
      cupIndex++;
    }

    // 딸기가 현재 블록을 모두 채울만큼 충분한 동안 반복
    while (getBoxCount(cupIndex) <= strawberryCount) {
      strawberryCount -= getBoxCount(cupIndex);
      cups[cupIndex]++;
      matchCount += cups[cupIndex];
      cupIndex++;
    }

    // 성냥을 넣는 마지막 블록
    if (0 < strawberryCount) {
      for (let i = 0; i < strawberryCount; i++) {
        boxes[cupIndex][i]++;
        matchCount += boxes[cupIndex][i];
      }
    }

    console.log(matchCount);
  }
}