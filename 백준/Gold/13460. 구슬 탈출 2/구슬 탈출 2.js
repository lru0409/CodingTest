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

const Y = 0;
const X = 1;

const RED = 'R';
const BLUE = 'B';
const EMPTY = '.';
const EXIT = 'O';

const TOP = 0;
const BOTTOM = 1;
const LEFT = 2;
const RIGHT = 3;

const DIR_Y = [-1, 1, 0, 0];
const DIR_X = [0, 0, -1, 1];

function solution(input) {
	const [N, M] = input[0].split(' ').map(Number);
	const visited = new Array(N).fill(null).map(() => 
		new Array(M).fill(null).map(() => 
			new Array(N).fill(null).map(() => 
				new Array(M).fill(false)
			)
		)
	);

	const data = {
		map: [],
		red: null,
		blue: null,
		count: 1,
	}

	for (let i = 1; i <= N; i++) {
		const line = input[i].split('');
		data.map.push(line);
		for (let j = 0; j < M; j++) {
			if (line[j] === RED) {
				data.red = [i - 1, j];
			} else if (line[j] == BLUE) {
				data.blue = [i - 1, j];
			}
		}
	}

	const copyData = function(data) {
		const copied = JSON.parse(JSON.stringify(data));
		return copied;
	}

	const moveBall = function(data, ball, dir) {
		let [cy, cx] = ball === 'B' ? data.blue : data.red;
		let ny, nx;
		while (true) {
			ny = cy + DIR_Y[dir];
			nx = cx + DIR_X[dir];
			if (data.map[ny][nx] === EXIT)
				return [ny, nx];
			if (data.map[ny][nx] !== EMPTY)
				break;
			cy = ny;
			cx = nx;
		}
		return [cy, cx];
	}

	const BFS = function() {
		const queue = [ data ];
		visited[data.red[Y]][data.red[X]][data.blue[Y]][data.blue[X]] = true;

		while (0 < queue.length) {
			const data = queue.shift();
			if (data.count > 10)
				return -1;

			let first, second;
			for (let dir = 0; dir < 4; dir++) {
				const nextData = copyData(data);
				if (dir === TOP) {
					first = nextData.blue[Y] < nextData.red[Y] ? 'B' : 'R';
					second = nextData.blue[Y] < nextData.red[Y] ? 'R' : 'B';
				} else if (dir === BOTTOM) {
					first = nextData.blue[Y] < nextData.red[Y] ? 'R' : 'B';
					second = nextData.blue[Y] < nextData.red[Y] ? 'B' : 'R';
				} else if (dir === LEFT) {
					first = nextData.blue[X] < nextData.red[X] ? 'B' : 'R';
					second = nextData.blue[X] < nextData.red[X] ? 'R' : 'B';
				} else if (dir === RIGHT) {
					first = nextData.blue[X] < nextData.red[X] ? 'R' : 'B';
					second = nextData.blue[X] < nextData.red[X] ? 'B' : 'R';
				}

				const [firstY, firstX] = moveBall(nextData, first, dir);
				if (nextData.map[firstY][firstX] !== EXIT)
					nextData.map[firstY][firstX] = first;
				if (first === 'R') {
					if (firstY !== nextData.red[Y] || firstX !== nextData.red[X])
						nextData.map[nextData.red[Y]][nextData.red[X]] = EMPTY;
					nextData.red[Y] = firstY;
					nextData.red[X] = firstX;
				} else if (first === 'B') {
					if (firstY !== nextData.blue[Y] || firstX !== nextData.blue[X])
						nextData.map[nextData.blue[Y]][nextData.blue[X]] = EMPTY;
					nextData.blue[Y] = firstY;
					nextData.blue[X] = firstX;
				}

				const [secondY, secondX] = moveBall(nextData, second, dir);
				if (nextData.map[secondY][secondX] !== EXIT)
					nextData.map[secondY][secondX] = second;
				if (second === 'R') {
					if (secondY !== nextData.red[Y] || secondX !== nextData.red[X])
						nextData.map[nextData.red[Y]][nextData.red[X]] = EMPTY;
					nextData.red[Y] = secondY;
					nextData.red[X] = secondX;
				} else if (second === 'B') {
					if (secondY !== nextData.blue[Y] || secondX !== nextData.blue[X])
						nextData.map[nextData.blue[Y]][nextData.blue[X]] = EMPTY;
					nextData.blue[Y] = secondY;
					nextData.blue[X] = secondX;
				}

				if (nextData.map[nextData.red[Y]][nextData.red[X]] === EXIT &&
					nextData.map[nextData.blue[Y]][nextData.blue[X]] !== EXIT) {
					return nextData.count;
				} else if (nextData.map[nextData.red[Y]][nextData.red[X]] === EXIT ||
					nextData.map[nextData.blue[Y]][nextData.blue[X]] === EXIT) {
					continue;
				}

				if (visited[nextData.red[Y]][nextData.red[X]][nextData.blue[Y]][nextData.blue[X]])
					continue;
				visited[nextData.red[Y]][nextData.red[X]][nextData.blue[Y]][nextData.blue[X]] = true;
				nextData.count += 1;
				queue.push(nextData);
			}
		}
		return -1;
	}

	console.log(BFS());
}