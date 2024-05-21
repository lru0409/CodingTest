function solution(n, m, section) {
    let answer = 0;
    let idx = 0;
    while (idx < section.length) {
        let space = section[idx] + m - 1;
        while (section[idx] <= space)
            idx++;
        answer += 1;
    }
    return answer;
}