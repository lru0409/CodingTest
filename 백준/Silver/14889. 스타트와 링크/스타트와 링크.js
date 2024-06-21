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

function solution(input ) {
	const N = parseInt(input[0]);
	const S = [];
	for (let i = 1; i <= N; i++) {
		S.push(input[i].split(' ').map(Number));
	}

	let answer = 1000;
	const team = new Array(N / 2);

	const checkDiff = function(ability) {
		let team1 = ability, team2 = 0;
		const otherTeam = [];
		let teamIndex = 0;
		for (let i = 0; i < N; i++) {
			if (i === team[teamIndex]) {
				teamIndex++;
				continue;
			}
			otherTeam.push(i);
		}
		for (let i = 0; i < otherTeam.length; i++) {
			for (let j = 0; j < otherTeam.length; j++) {
				team2 += S[otherTeam[i]][otherTeam[j]];
			}
		}
		answer = Math.min(answer, Math.abs(team1 - team2));
	}

	const combination = function(count, index, ability) {
		if (count === N / 2) {
			checkDiff(ability);
			return;
		}
		for (let i = index; i < N; i++) {
			let addAbility = 0;
			for (let j = 0; j < count; j++) {
				addAbility += S[team[j]][i];
				addAbility += S[i][team[j]];
			}
			team[count] = i;
			combination(count + 1, i + 1, ability + addAbility);
		}
	}

	combination(0, 0, 0);
	console.log(answer);
}