function solution(numbers) {
    let answer = 0;
    
    const isExist = new Array(10).fill(false);
    numbers.forEach((number) => {
        isExist[number] = true;
    });
    isExist.forEach((exist, index) => {
        if (!exist) answer += index;
    });
    
    return answer;
}