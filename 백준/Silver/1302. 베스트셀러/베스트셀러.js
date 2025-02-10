const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", (close) => {
  const N = parseInt(input.shift());
  solution(N, input);
});

const solution = (N, titles) => {
  const titleCounter = {};
  let candidates = [];
  let maxCount = 0;
  titles.forEach((title) => {
    if (!titleCounter[title]) titleCounter[title] = 0;
    titleCounter[title]++;
    if (maxCount < titleCounter[title]) {
      maxCount = titleCounter[title];
      candidates = [];
    }
    if (maxCount === titleCounter[title]) {
      candidates.push(title);
    }
  });
  candidates.sort();
  console.log(candidates[0]);
};
