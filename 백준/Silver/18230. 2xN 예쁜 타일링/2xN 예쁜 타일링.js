


// N이 홀수면 세로 타일이 홀수개 필요함
// N이 짝수면 세로 타일이 없어도 되거나 짝수개 필요함

// 가장 이득은 값 높은 세로 타일을 최대한 놓는 것

// 세로 타일을 내림차순 정렬시키고 두개씩 묶는다.
// 정사각형 타일도 내림차순으로 정렬시킨다.


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
    const [N, A, B] = input[0].split(" ").map(Number);
    const rectangles = input[1].split(" ").map(Number);
    const squares = input[2].split(" ").map(Number);
    solution(N, A, B, rectangles, squares);
});

function solution(N, A, B, rectangles, squares) {
    // 타일들을 내림차순으로 정렬
    rectangles.sort((a, b) => b - a);
    squares.sort((a, b) => b - a);

    let answer = 0;
    let recIdx = 0;
    let sqIdx = 0;
    if (N % 2 === 1) {
        // 무조건 직사각형 하나가 필수
        answer += rectangles[recIdx++];
        N -= 1;
    }
    while (0 < N) { // 
        N -= 2;
        if (sqIdx < squares.length && recIdx + 1 < rectangles.length) {
            const sqValue = squares[sqIdx];
            const recValue = rectangles[recIdx] + rectangles[recIdx + 1];
            // sqValue와 recValue 중 더 큰 걸로 채우기
            if (sqValue < recValue)  {
                answer += recValue;
                recIdx += 2;
            } else {
                answer += sqValue;
                sqIdx++;
            }
            continue;
        }
        if (sqIdx < squares.length) {
            const sqValue = squares[sqIdx];
            answer += sqValue;
            sqIdx++;
        }
        if (recIdx + 1 < rectangles.length) {
            const recValue = rectangles[recIdx] + rectangles[recIdx + 1];
            answer += recValue;
            recIdx += 2;
        }
    }
    console.log(answer);
}