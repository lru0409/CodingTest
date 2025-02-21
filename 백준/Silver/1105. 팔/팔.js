const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

let input;
rl.on("line", (line) => {
  input = line;
}).on("close", (close) => {
    const [L, R] = input.split(" ");
    solution (L, R);
});

const solution = (L, R) => {
    if (L.length !== R.length) {
        console.log(0)
        return;
    }
    let count = 0;
    for (let i = 0; i < L.length; i++) {
        if (L[i] !== "8" && L[i] === R[i]) continue;
        if (L[i] !== "8" || R[i] !== "8") break;
        count++;
    }
    console.log(count);
}

// 두 수의 자릿수가 다를 경우 => 0
// 앞자리부터 둘 다 8인 자릿수까지 이동하며 카운트 세기