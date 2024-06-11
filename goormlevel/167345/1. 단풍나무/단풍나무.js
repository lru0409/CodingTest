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
	const N = parseInt(input[0]);
	let park = [];
	let count = 0;
	for (let i = 1; i < N + 1; i++) {
		const line = input[i].split(' ').map(Number);
		line.forEach((num) => {
			if (num !== 0) count++;
		})
		park.push(line);
	}
	
	const dy = [ -1, 1, 0, 0 ];
	const dx = [ 0, 0, -1, 1 ];
	const changeTree = function() {
	
		const getAroundCount = function(y, x) {
			let aroundCount = 0;
			for (let i = 0; i < 4; i++) {
				let ny = y + dy[i];
				let nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)
					continue;
				if (park[ny][nx] === 0)
					aroundCount++;
			}
			return aroundCount;
		}
		
		const changedPark = JSON.parse(JSON.stringify(park));
		for (let y = 0; y < N; y++) {
			for (let x = 0; x < N; x++) {
				if (park[y][x] === 0)
					continue;
				const aroundCount = getAroundCount(y, x);
				changedPark[y][x] = Math.max(0, park[y][x] - aroundCount);
				if (changedPark[y][x] === 0)
					count--;
			}
		}
		park = changedPark;
	}
	
	let day = 0;
	while (count) {
		changeTree();
		day++;
	}
	
	console.log(day);
}