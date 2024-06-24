const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

const input = [];

rl.on("line", (line) => {
	input.push(line);
}).on("close", () => {
	solution(input);
})

const DY = [-1, 1, 0, 0];
const DX = [0, 0, -1, 1];

function solution(input) {
	const N = parseInt(input[0]);
	const space = new Array(N).fill(null).map(() => Array(N).fill(0));

	const getArounds = function([y, x]) {
		const arounds = [];
		for (let dir = 0; dir < 4; dir++) {
			const ny = y + DY[dir], nx = x + DX[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			arounds.push(space[ny][nx]);
		}
		return arounds;
	}

	const getLikeArounds = function(like) {
		let maxCount = -1;
		let likeArounds = [];

		for (let y = 0; y < N; y++) {
			for (let x = 0; x < N; x++) {
				if (space[y][x] !== 0)
					continue;
				const arounds = getArounds([y, x]);
				let count = 0;
				arounds.forEach((around) => {
					if (like.includes(around))
						count++;
				})
				if (maxCount < count) {
					likeArounds = [];
					maxCount = count;
				}
				if (maxCount === count)
					likeArounds.push([y, x]);
			}
		}
		return likeArounds;
	}

	const getEmptyArounds = function(candidates) {
		let maxCount = -1;
		let emptyArounds = [];
		for (candidate of candidates) {
			const arounds = getArounds(candidate);
			let count = 0;
			arounds.forEach((around) => {
				if (around === 0)
					count++;
			})
			if (maxCount < count) {
				emptyArounds = [];
				maxCount = count;
			}
			if (maxCount === count)
				emptyArounds.push(candidate);
		}
		return emptyArounds;
	}

	const likeMap = new Map();

	// 1. 자리 배정하기
	for (let i = 1; i <= N * N; i++) {
		[num, ...like] = input[i].split(' ').map(Number);
		likeMap.set(num, like);
		
		const likeArounds = getLikeArounds(like); // 좋아하는 학생이 인접한 칸에 가장 많은 빈 칸들 구하기
		const emptyArounds = getEmptyArounds(likeArounds); // 인접한 칸 중에서 비어있는 칸이 가장 많은 칸들 구하기
		emptyArounds.sort((a, b) => {
			if (a[0] !== b[0])
				return a[0] - b[0];
			return a[1] - b[1];
		})
		const [y, x] = emptyArounds[0];
		space[y][x] = num; // 행의 번호가 가장 작고, 열의 번호가 가장 작은 칸으로 고르기
	}

	// 2. 만족도의 총합 구하기
	let answer = 0;
	for (let y = 0; y < N; y++) {
		for (let x = 0; x < N; x++) {
			const arounds = getArounds([y, x]);
			const likes = likeMap.get(space[y][x]);
			let score = arounds.reduce((score, around) => {
				if (likes.includes(around)) {
					return score === 0 ? 1 : score * 10;
				}
				return score;
			}, 0);
			answer += score;
		}
	}

	console.log(answer);
}