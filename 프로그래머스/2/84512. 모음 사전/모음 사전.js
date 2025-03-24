function solution(word) {
    const index = { // 알파벳 별 인덱스
        "A": 0, "E": 1, "I": 2, "O": 3, "U": 4
    }
    let answer = 0;
    let totalCount = 0;
    for (let i = 0; i < word.length; i++) {
        const alphabet = word[i];
        let count = 1; // i 인덱스로 한 알파벳이 들어올 때의 모든 경우의 수 개수를 구할 예정
        for (let j = 1; j < 5 - i; j++) {
            count += Math.pow(5, j);
        }
        totalCount += index[alphabet] * count + 1; // i 인덱스로 alphabet 이전의 문자가 왔을 때, 모든 경우의 수 개수 + 1 = 현재 개수
    }
    return totalCount;
}

// 5P1 => 5
// 5P2 => 25
// 5P3 => 125
// 5P4 => 625
// 5P5 => 3125

// 첫 글자 인덱스 * 781(1 + 5P1 + 5P2 + 5P3 + 5P4) + 1
// 두 글자 인덱스 * 156(1 + 5P1 + 5P2 + 5P3) + 1
// 세 글자 인덱스 * 31(1 + 5P1 + 5P2) + 1
// 네 글자 인덱스 * 6(1 + 5P1) + 1
// 다섯 글자 인덱스 + 1


