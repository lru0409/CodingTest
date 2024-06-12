// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	const input = [];
	
	for await (const line of rl) {
		input.push(line);
		rl.close();
	}
	
	solution(input);
	
	process.exit();
})();

function solution(input) {
	const [ N, Q ] = input[0].split(' ').map(Number);
	const map = [];
	const Y = 0;
	const X = 1;
	
	for (let i = 1; i < N + 1; i++) {
		map.push(input[i].split(' ').map(Number));
	}
	
	const createComparator = function(first, second) {
		return function(point1, point2) {
			if (point1[first] !== point2[first])
				return point1[first] - point2[first];
			return point1[second] - point2[second];
		}
	}

	for (let i = N + 1; i < N + Q + 1; i++) {
		const [ y1, x1, y2, x2, y3, x3 ] = input[i].split(' ').map(Number);

		const triangle = [ [y1, x1], [y2, x2], [y3, x3] ];
		const ySorted = [...triangle].sort(createComparator(Y, X));
		const xSorted = [...triangle].sort(createComparator(X, Y));
		
		let yDir = ySorted[0][Y] === ySorted[1][Y] ? 'top' : 'bottom';
		let xDir = xSorted[0][X] === xSorted[1][X] ? 'left' : 'right';
		let yMin = ySorted[0][Y], xMin = xSorted[0][X];
		let yMax = ySorted[2][Y], xMax = xSorted[2][X];
		
		let sum = 0;
		if (yDir === 'top' && xDir === 'left') {
			let tmpXMax = xMax;
			for (let y = yMin; y <= yMax; y++) {
				for (let x = xMin; x <= tmpXMax; x++) {
					sum += map[y - 1][x - 1];
				}
				tmpXMax--;
			}
		} else if (yDir === 'top' && xDir === 'right') {
			let tmpXMin = xMin;
			for (let y = yMin; y <= yMax; y++) {
				for (let x = tmpXMin; x <= xMax; x++) {
					sum += map[y - 1][x - 1];
				}
				tmpXMin++;
			}
		} else if (yDir === 'bottom' && xDir === 'left') {
			let tmpXMin = xMin;
			for (let y = yMin; y <= yMax; y++) {
				for (let x = xMin; x <= tmpXMin; x++) {
					sum += map[y - 1][x - 1];
				}
				tmpXMin++;
			}
		} else if (yDir === 'bottom' && xDir === 'right') {
			let tmpXMax = xMax;
			for (let y = yMin; y <= yMax; y++) {
				for (let x = tmpXMax; x <= xMax; x++) {
					sum += map[y - 1][x - 1];
				}
				tmpXMax--;
			}
		}
		console.log(sum);
	}
}
