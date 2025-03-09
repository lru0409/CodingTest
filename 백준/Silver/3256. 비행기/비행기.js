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
  const [N, ...passengers] = input.map(Number);
  solution(N, passengers);
});

function solution(N, passengers) {
  let time = 0;
  let passengerIdx = 0;
  const passage = new Array(1000).fill(null); // { seatRow, loadingTimer }

  while (true) {
    // 복도 시작에 승객 한 명 추가하기
    if (passage[0] === null && passengerIdx < passengers.length) {
      passage[0] = { seatRow: passengers[passengerIdx++], loadingTimer: 5 };
    }
    // 복도의 승객들 한 칸씩 전진하기
    let isEmptyPassage = true;
    for (let i = 999; i >= 0; i--) {
      if (!passage[i]) continue;
      isEmptyPassage = false;
      if (passage[i].seatRow === i + 1) {
        passage[i].loadingTimer -= 1;
        if (passage[i].loadingTimer === 0) {
          passage[i] = null;
        }
        continue;
      }
      if (passage[i].loadingTimer !== 5 || i === 999) continue;
      if (passage[i + 1] !== null) continue;
      passage[i + 1] = passage[i];
      passage[i] = null;
    }
    if (isEmptyPassage && passengers.length <= passengerIdx) break;
    time++;
  }
  console.log(time);
}
