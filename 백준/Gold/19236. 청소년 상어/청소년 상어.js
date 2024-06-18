const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
})

const input = [];

rl.on('line', (line) => {
	input.push(line.split(' ').map(Number));
}).on('close', () => {
	solution(input);
})

const Y = 0;
const X = 1;
const DIR = 2;

const SHARK = 0;

const DIR_Y = [-1, -1, 0, 1, 1, 1, 0, -1];
const DIR_X = [0, -1, -1, -1, 0, 1, 1, 1];

function solution(input) {

	const data = {
		fish: new Array(17).fill(null).map(() => Array(3)), // 각 물고기마다 [y, x, dir]
		space: new Array(4).fill(null).map(() => Array(4)), // 공간의 현재 상태
		shark: null, // 상어의 [y, x, dir]
		eatSum: 0, // 상어가 먹은 물고기 번호의 합
	}

	// 공간 및 물고기 정보 초기화
	for (let y = 0; y < 4; y++) {
		for (let x = 0; x < 4; x++) {
			const fishNum = input[y][x * 2];
			const fishDir = input[y][x * 2 + 1];
			data.fish[fishNum][Y] = y;
			data.fish[fishNum][X] = x;
			data.fish[fishNum][DIR] = fishDir - 1;
			data.space[y][x] = fishNum;
		}
	}
	
	// 상어가 (0, 0)에 있는 물고기를 먹음
	data.eatSum = data.space[0][0];
	data.shark = [0, 0, data.fish[data.space[0][0]][DIR]];
	data.fish[data.space[0][0]] = null;
	data.space[0][0] = SHARK;

	const move = function(cy, cx, dir) {
		return [cy + DIR_Y[dir], cx + DIR_X[dir]];
	}

	const moveFish = function(data, num) { // num 번호의 물고기를 이동시키는 함수
		const [cy, cx] = [data.fish[num][Y], data.fish[num][X]];
		let ny, nx;
		while (true) { // 이동할 칸을 찾는 반복문
			[ny, nx] = move(cy, cx, data.fish[num][DIR]);
			if ((0 <= ny && ny < 4) && (0 <= nx && nx < 4) && data.space[ny][nx] !== SHARK)
				break; // 찾았으면 탈출
			data.fish[num][DIR] = (data.fish[num][DIR] + 1) % 8; // 못 찾았으면 반시계 45도 회전
		}
		// 물고기 이동 (기존에 그 자리에 있던 물고기와 스왑)
		const swapFish = data.space[ny][nx];
		if (swapFish !== null) {
			data.fish[swapFish][Y] = cy;
			data.fish[swapFish][X] = cx;
		}
		data.space[cy][cx] = swapFish;
		data.fish[num][Y] = ny;
		data.fish[num][X] = nx;
		data.space[ny][nx] = num;
	}

	const copy = function(data) {
		const copied = JSON.parse(JSON.stringify(data));
		return copied;
	}

	let answer = 0;

	const BFS = function() {
		const queue = [ data ];
		
		while (0 < queue.length) {
			const data = queue.shift();
			answer = Math.max(answer, data.eatSum);

			// 모든 물고기 움직이기
			for (let fishNum = 1; fishNum <= 16; fishNum++) {
				if (data.fish[fishNum] !== null)
					moveFish(data, fishNum);
			}

			// 상어 움직이기
			let [sharkY, sharkX] = [data.shark[Y], data.shark[X]];
			while (true) {
				const [ny, nx] = move(sharkY, sharkX, data.shark[DIR]);
				if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
					break; // 더 이상 이동할 공간이 없는 경우 탈출
				if (data.space[ny][nx] !== null) { // 이동할 공간을 찾은 경우
					const newData = copy(data); // data 객체 복사본 생성 후 세팅
					const eatFish = data.space[ny][nx];
					newData.eatSum += eatFish;
					newData.space[data.shark[Y]][data.shark[X]] = null;
					newData.space[ny][nx] = SHARK;
					newData.shark = [ny, nx, data.fish[eatFish][DIR]];
					newData.fish[eatFish] = null;
					queue.push(newData);
				}
				sharkY = ny;
				sharkX = nx;
			}
		}
	}

	BFS();
	console.log(answer);
}