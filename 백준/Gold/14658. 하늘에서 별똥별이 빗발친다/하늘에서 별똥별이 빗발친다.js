const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [N, M, L, K] = input.shift().split(" ").map(Number);
	const stars = input.map((line) => {
		const [x, y] = line.split(" ").map(Number);
		return { x, y };
	})
	solution(N, M, L, stars);
});

function solution(N, M, L, stars) {
	let minCount = 100;

	for (let i = 0; i < stars.length; i++) {
		for (let j = 0; j < stars.length; j++) {
			// 두 별똥별 선택
			// 두 별똥별의 최소 x, y를 왼쪽 최상단으로 하는 범위 설정
			// 범위를 벗어나는 별똥별의 개수 세기
			let count = 0;
			const y = Math.min(stars[i].y, stars[j].y);
			const x = Math.min(stars[i].x, stars[j].x);
			stars.forEach((star) => {
				if (star.y < y || y + L < star.y ||
					star.x < x || x + L < star.x)
					count++;
			});
			minCount = Math.min(minCount, count);
		}
	}

	console.log(minCount);
}