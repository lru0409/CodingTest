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

const DIR_Y = [-1, 0, 1, 0];
const DIR_X = [0, 1, 0, -1];

const Y = 0;
const X = 1;
const DIR = 2;

const WALL = 1;

function solution(input) {
	const [N, M] = input[0].split(' ').map(Number);
	const robot = input[1].split(' ').map(Number);
	const room = [];
	for (let i = 2; i <= N + 1; i++) {
		room.push(input[i].split(' ').map(Number));
	}
	const cleaned = new Array(N).fill(null).map(() => Array(M).fill(false));
	let answer = 0;

	const move = function(cy, cx, dir) {
		const ny = cy + DIR_Y[dir];
		const nx = cx + DIR_X[dir];
		return [ny, nx];
	}

	while (true) {
		if (cleaned[robot[Y]][robot[X]] === false) {
			cleaned[robot[Y]][robot[X]] = true;
			answer++;
		}
		let clean = true;
		for (let dir = 0; dir < 4; dir++) {
			const [ny, nx] = move(robot[Y], robot[X], dir);
			if (room[ny][nx] !== WALL && cleaned[ny][nx] === false) {
				clean = false;
				break;
			}
		}
		if (clean === false) {
			robot[DIR] = (robot[DIR] + 3) % 4;
			const [ny, nx] = move(robot[Y], robot[X], robot[DIR])
			if (room[ny][nx] !== WALL && cleaned[ny][nx] === false) {
				[robot[Y], robot[X]] = [ny, nx];
			}
		} else {
			const [ny, nx] = move(robot[Y], robot[X], (robot[DIR] + 2) % 4);
			if (room[ny][nx] === WALL)
				break;
			[robot[Y], robot[X]] = [ny, nx];
		}
	}

	console.log(answer);
}