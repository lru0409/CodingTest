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
        if (L[i] !== R[i]) break;
        if (L[i] === "8" && R[i] === "8") count++;
    }
    console.log(count);
}