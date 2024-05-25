function solution(numbers)
{
    const stack = []; // 뒷 큰수를 찾지 못한 원소의 인덱스
    const answer = new Array(numbers.length).fill(-1);
    
    for(let i = 0; i < numbers.length; i++) {
        while (stack.length && numbers[stack.at(-1)] < numbers[i]) {
            answer[stack.pop()] = numbers[i];
        }
        stack.push(i);
    }

    return answer;
}