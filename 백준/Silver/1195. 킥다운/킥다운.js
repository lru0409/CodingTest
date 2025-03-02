const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const shorter = input[0].length <= input[1].length ? input[0] : input[1];
  const longer = input[0].length > input[1].length ? input[0] : input[1];
  solution(shorter, longer);
});

function solution(shorter, longer) {
  let minWidth = shorter.length + longer.length;
  for (let i = 0; i < shorter.length + longer.length - 1; i++) {
    const start = Math.max(0, i - longer.length + 1);
    const end = Math.min(i, shorter.length - 1);
    const longerStart = Math.max(0, longer.length - i - 1);
    let fit = true;
    for (let j = 0; j <= end - start; j++) {
      if (shorter[start + j] === "2" && longer[longerStart + j] === "2") {
        fit = false;
        break;
      }
    }
    if (fit) {
      minWidth = Math.min(
        minWidth,
        shorter.length + longer.length - (end - start + 1)
      );
    }
  }

  console.log(minWidth);
}
