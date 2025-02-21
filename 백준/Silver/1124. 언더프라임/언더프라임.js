const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

let input;
rl.on("line", (line) => {
  input = line;
}).on("close", (close) => {
    const [A, B] = input.split(" ").map(Number);
    solution (A, B);
});

const solution = (A, B) => {
    const getIsPrime = (N) => {
        const isPrime = new Array(N + 1).fill(true);
        isPrime[1] = false;
        for (let i = 2; i < N; i++) {
            if (!isPrime[i]) continue;
            for (let j = 2; i * j <= N; j++ ) {
                isPrime[i * j] = false;
            }
        }
        return isPrime;
    }
    const factorization = (N) => {
        let count = 1;
        while (!isPrime[N]) {
            // N을 나눌 수 있는 가장 작은 소수 찾기
            for (let i = 2; i <= N; i++) {
                if (N % i === 0 && isPrime[i]) {
                    N /= i;
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    const isPrime = getIsPrime(Math.max(A, B));
    let answer = 0;
    for (let i = A; i <= B; i++) {
        const count = factorization(i);
        if (isPrime[count]) answer++;
    }
    console.log(answer);
}