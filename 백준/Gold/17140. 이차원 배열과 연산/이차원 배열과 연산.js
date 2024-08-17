const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin, output: process.stdout
});

const input = [];

rl.on('line', (line) => {
	input.push(line);
}).on('close', () => {
	const [r, c, k] = input.shift().split(" ").map(Number);
	const A = input.map((row) => row.split(" ").map(Number));
	const paddedA = Array(100).fill(null).map(() => Array(100).fill(0));
	for (let i = 0; i < 3; i++) {
		for (let j = 0; j < 3; j++) {
			paddedA[i][j] = A[i][j];
		}
	}
	solution(r - 1, c - 1, k, paddedA);
});

function solution(r, c, k, A) {
	let rowCount = 3;
	let columnCount = 3;
	let time = 0;

	while (time <= 100 && A[r][c] !== k) {
		if (rowCount < columnCount) { // C 연산
			rowCount = cOperation(A, columnCount, rowCount);
		} else { // R 연산
			columnCount = rOperation(A, rowCount, columnCount);
		}
		time++;
	}
	
	console.log(time <= 100 ? time : -1);
}

function cOperation(A, columnCount, rowCount) {
	for (let c = 0; c < columnCount; c++) { // 한 열씩 정렬
		const arr = A.slice(0, rowCount).map(row => row[c]); // 배열로 뽑아오기
		const sorted = sortArr(arr); // 정렬된 상태
		for (let r = 0; r < 100; r++) { // 기존 배열에 정렬된 상태를 적용
			A[r][c] = r < sorted.length ? sorted[r] : 0;
		}
		rowCount = Math.min(100, Math.max(rowCount, sorted.length)); // rowCount 갱신
	}
	return rowCount;
}

function rOperation(A, rowCount, columnCount) {
	for (let r = 0; r < rowCount; r++) { // 한 행씩 정렬
		const arr = A[r].slice(0, columnCount);
		const sorted = sortArr(arr); // 정렬된 상태
		for (let c = 0; c < 100; c++) { // 기존 배열에 정렬된 상태를 적용
			A[r][c] = c < sorted.length ? sorted[c] : 0;
		}
		columnCount = Math.min(100, Math.max(columnCount, sorted.length)); // columnCount 갱신
	}
	return columnCount;
}


function sortArr(arr) {
	const counter = arr.reduce((counter, num) => {
		if (num !== 0) counter.set(num, (counter.get(num) || 0) + 1);
		return counter;
	}, new Map());
	const sorted = Array.from(counter).sort(([num1, cnt1], [num2, cnt2]) => {
		return cnt1 !== cnt2 ? cnt1 - cnt2 : num1 - num2;
	}).flat();
	return sorted;
}
