const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin, ouput: process.stdout,
});

const input = [];
rl.on("line", (line) => {
    input.push(line);
}).on("close", (close) => {
    const N = parseInt(input.shift());
    const classesByGrade = input.map((line) => line.split(" ").map(Number));
    solution(N, classesByGrade);
});

const solution = (N, classesByGrade) => {
    const sameClass = new Array(N).fill(null).map(() => new Array());

    for (let grade = 0; grade < 5; grade++) {
        const studentsByClass = {};
        // 맵으로 각 학년당 반 - 학생 번호 배열 얻기
        for (let student = 0; student < N; student++) {
            const currentClass = classesByGrade[student][grade];
            if (!studentsByClass[currentClass]) {
                studentsByClass[currentClass] = [];
            }
            studentsByClass[currentClass].push(student);
        }
        
        // 맵 순회하면서 학생 번호가 2개 이상이면, sameClass 배열에 추가하기
        for (const students of Object.values(studentsByClass)) {
            if (students.length <= 1) continue;
            for (let i = 0; i < students.length; i++) {
                for (let j = 0; j < students.length; j++) {
                    if (i === j) continue;
                    if (sameClass[students[i]].includes(students[j])) continue;
                    sameClass[students[i]].push(students[j]);
                }
            }
        }
    }

    // sameClass 순회하면서 가장 학생 배열의 길이가 큰 인덱스 찿기
    let resultStudent = 0;
    for (let i = 0; i < sameClass.length; i++) {
        if (sameClass[resultStudent].length < sameClass[i].length) {
            resultStudent = i;
        }
    }
    console.log(resultStudent + 1);
}