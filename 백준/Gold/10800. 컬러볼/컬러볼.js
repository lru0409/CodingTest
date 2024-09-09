const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const N = parseInt(input.shift());
	const balls = input.map((line, number) => {
		const [color, size] = line.split(" ").map(Number);
		return { color, size, number: number + 1 };
	});
	solution(N, balls);
});

function solution(N, balls) {
	balls.sort((a, b) => a.size - b.size); // size 기준으로 balls 정렬

	let sizeSum = 0; // size가 바뀔 때마다 업데이트되는 크기 누적합
	const sizeSumPerColor = {}; // size가 바뀔 때마다 업데이트되는 색깔 별 크기 누적합
	let prevSize = balls[0].size;
	let tempBalls = [];
	const result = new Array(N).fill(0);

	balls.forEach(({color, size, number}) => {
		// 크기가 바뀔 때마다 sizeSum, sizeSumPerColor 업데이트
		if (prevSize !== size) {
			tempBalls.forEach(({color, size}) => {
				sizeSum += size;
				sizeSumPerColor[color] = sizeSumPerColor[color] || 0;
				sizeSumPerColor[color] += size;
			});
			tempBalls = [];
			prevSize = size;
		}
		// 지금까지 누적합 - 지금까지 같은 색상의 누적합
		result[number - 1] = sizeSum - (sizeSumPerColor[color] || 0);
		tempBalls.push({color, size});
	});

	// i번째 공이 잡을 수 있는 크기 합 출력
	process.stdout.write(result.join('\n') + '\n');
}