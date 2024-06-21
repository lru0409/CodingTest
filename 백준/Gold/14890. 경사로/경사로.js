const { posix } = require('path');
const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	solution(input);
})

function solution(input) {
	const [N, L] = input[0].split(' ').map(Number);
	const map = [];
	for (let i = 1; i <= N; i++) {
		map.push(input[i].split(' ').map(Number));
	}
	let answer = 0;

	const checkPath = function(dir) {
		const tempMap = map.map((line) => line.slice());

		for (let line = 0; line < N; line++) {
			let prevHigh;
			if (dir === 'row') prevHigh = map[line][0];
			else if (dir === 'col') prevHigh = map[0][line];

			let i;
			for (i = 1; i < N; i++) {
				let currentHigh;
				if (dir === 'row') currentHigh = map[line][i];
				else if (dir === 'col') currentHigh = map[i][line];

				if (currentHigh === prevHigh)
					continue;
				if (1 < Math.abs(currentHigh - prevHigh))
					break;
				if (prevHigh < currentHigh) {
					let tempI = i - 1;
					while (tempI > i - 1 - L && tempI >= 0) {
						if (dir === 'row' && tempMap[line][tempI] === -1) break;
						if (dir === 'col' && tempMap[tempI][line] === -1) break;
						if (dir === 'row') tempMap[line][tempI] = -1;
						else if (dir === 'col') tempMap[tempI][line] = -1;
						tempI--;
					}
					if (tempI !== i - 1 - L)
						break;
				}
				else if (prevHigh > currentHigh) {
					let tempI = i;
					while (tempI < i + L && tempI < N) {
						let tempCurrentHigh;
						if (dir === 'row') {
							tempCurrentHigh = map[line][tempI];
							tempMap[line][tempI] = -1;
						} else if (dir === 'col') {
							tempCurrentHigh = map[tempI][line];
							tempMap[tempI][line] = -1;
						}
						if (currentHigh !== tempCurrentHigh)
							break;
						tempI++;
					}
					if (tempI !== i + L)
						break;
				}
				prevHigh = currentHigh;
			}
			if (i === N)
				answer++;
		}
	}

	checkPath('row');
	checkPath('col');

	console.log(answer);
}