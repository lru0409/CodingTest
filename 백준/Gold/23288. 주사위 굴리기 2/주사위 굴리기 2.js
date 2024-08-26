const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [ N, M, K ] = input.shift().split(" ").map(Number);
	const map = input.map((line) => line.split(" ").map(Number));
	solution(N, M, K, map);
});

const NORTH = 0;
const EAST = 1;
const SOUTH = 2;
const WEST = 3;

const TOP = 0;
const FRONT = 1
const BOTTOM = 2;
const BACK = 3;
const LEFT = 4;
const RIGHT = 5;

const Y = 0;
const X = 1;

const ROLL = [
	[BACK, TOP, FRONT, BOTTOM], // NORTH
	[RIGHT, TOP, LEFT, BOTTOM], // EAST
	[FRONT, TOP, BACK, BOTTOM], // SOUTH
	[LEFT, TOP, RIGHT, BOTTOM], // WEST
];

const DY = [-1, 0, 1, 0];
const DX = [0, 1, 0, -1];

function solution(N, M, K, map) {
	let score = 0;
	const dice = [1, 5, 6, 2, 4, 3]; // 위, 앞, 아래, 뒤, 왼, 오
	let diceDir = EAST;
	const dicePos = [0, 0];

	while (K--) {
		// 주사위 한 칸 굴리기
		diceDir = rollDice(dice, diceDir, dicePos, N, M);
		// 현재 주사위 위치에서 동서남북 방향으로 연속해 이동할 수 있는 칸의 수 구하기
		const count = BFS(dicePos, map, N, M);
		const mapNumber = map[dicePos[Y]][dicePos[X]];
		score += mapNumber * count; // 점수 획득하기
		// 이동 방향 결정하기
		if (dice[BOTTOM] > mapNumber) {
			diceDir = (diceDir + 1) % 4;
		} else if (dice[BOTTOM] < mapNumber) {
			diceDir = (diceDir + 3) % 4;
		}
	}
	console.log(score);
}

function rollDice(dice, dir, pos, N, M) {
	pos[Y] += DY[dir];
	pos[X] += DX[dir];
	if (pos[Y] < 0 || pos[X] < 0 || pos[Y] >= N || pos[X] >= M) {
		dir = (dir + 2) % 4;
		pos[Y] += (DY[dir] * 2);
		pos[X] += (DX[dir] * 2);
	}
	const roll = ROLL[dir];
	const temp = dice[roll[0]];
	for (let i = 0; i < 3; i++) {
		dice[roll[i]] = dice[roll[i + 1]];
	}
	dice[roll[3]] = temp;
	return dir;
}

function BFS([y, x], map, N, M) {
	const queue = [ [y, x] ];
	const visited = new Array(N).fill(null).map(() => Array(M).fill(false));
	visited[y][x] = true;
	
	let count = 0;
	while (queue.length) {
		const [cy, cx] = queue.shift();
		count++;
		for (let i = 0; i < 4; i++) {
			const ny = cy + DY[i];
			const nx = cx + DX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] || map[ny][nx] !== map[y][x]) continue;
			visited[ny][nx] = true;
			queue.push([ny, nx]);
		}
	}
	return count;
}
