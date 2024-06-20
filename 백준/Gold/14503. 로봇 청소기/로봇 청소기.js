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
	cleaned[robot[Y]][robot[X]] = true;
	let answer = 1;

	const move = function(cy, cx, dir) {
		const ny = cy + DIR_Y[dir];
		const nx = cx + DIR_X[dir];
		return [ny, nx];
	}

	while (true) {
		let cleanAround = true;
		let dir_temp = robot[DIR];
		for (let i = 0; i < 4; i++) {
			dir_temp = (dir_temp + 3) % 4;
			const [ny, nx] = move(robot[Y], robot[X], dir_temp);
			if (room[ny][nx] !== WALL && cleaned[ny][nx] === false) {
				cleanAround = false;
				cleaned[ny][nx] = true;
				[ robot[Y], robot[X], robot[DIR] ] = [ ny, nx, dir_temp ];
				answer++;
				break;
			}
		}
		if (cleanAround === true) {
			const [ny, nx] = move(robot[Y], robot[X], (robot[DIR] + 2) % 4);
			if (room[ny][nx] === WALL)
				break;
			[robot[Y], robot[X]] = [ny, nx];
		}
	}

	console.log(answer);
}