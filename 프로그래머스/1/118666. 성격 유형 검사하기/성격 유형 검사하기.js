function solution(survey, choices) {
    
    const pointMap = new Map([
        ['R', 0], ['T', 0],
        ['C', 0], ['F', 0],
        ['J', 0], ['M', 0],
        ['A', 0], ['N', 0],
    ]);
    
    for (let i = 0; i < survey.length; i++) {
        choices[i] -= 4;
        if (choices[i] < 0) { // 비동의
            pointMap.set(survey[i][0], pointMap.get(survey[i][0]) + Math.abs(choices[i]));
        } else if (choices[i] > 0) { // 동의
            pointMap.set(survey[i][1], pointMap.get(survey[i][1]) + choices[i]);
        }
    }
    
    let answer = '';
    answer += pointMap.get('R') >= pointMap.get('T') ? 'R' : 'T';
    answer += pointMap.get('C') >= pointMap.get('F') ? 'C' : 'F';
    answer += pointMap.get('J') >= pointMap.get('M') ? 'J' : 'M';
    answer += pointMap.get('A') >= pointMap.get('N') ? 'A' : 'N';

    return answer;
}