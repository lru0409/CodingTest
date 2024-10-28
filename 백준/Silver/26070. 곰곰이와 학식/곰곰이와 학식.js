const readline = require("readline");
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [A, B, C] = input[0].split(" ").map(Number);
    const [X, Y, Z] = input[1].split(" ").map(Number);
    solution(A, B, C, X, Y, Z);
});

const solution = (A, B, C, X, Y, Z) => {
    let count = 0;

    const eat = (bearCount, ticketCount) => {
        // 곰 마릿수, 식권 개수를 가지고 최대한 먹이는 함수
        const eattingCount = Math.min(bearCount, ticketCount);
        count += eattingCount;
        bearCount = bearCount - eattingCount;
        ticketCount = ticketCount - eattingCount;
        return [bearCount, ticketCount];
    }

    // 현재 식권으로 먹일 수 있는 만큼 일단 먹인다.
    [A, X] = eat(A, X);
    [B, Y] = eat(B, Y);
    [C, Z] = eat(C, Z);

    // 식권을 교환하고 추가로 먹인다.
    const exchangeTickets = (from, to) => {
        to += Math.floor(from / 3);
        from %= 3;
        return [from, to];
    }
    [X, Y] = exchangeTickets(X, Y);
    [B, Y] = eat(B, Y);
    [Y, Z] = exchangeTickets(Y, Z);
    [C, Z] = eat(C, Z);
    [Z, X] = exchangeTickets(Z, X);
    [A, X] = eat(A, X);
    [X, Y] = exchangeTickets(X, Y);
    [B, Y] = eat(B, Y);

    console.log(count);
}
