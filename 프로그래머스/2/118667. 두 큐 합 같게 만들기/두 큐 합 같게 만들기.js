function solution(queue1, queue2) {
    
    const total = queue1.length + queue2.length;
    let sum1 = 0, sum2 = 0;
    let index1 = 0, index2 = 0;
    let answer = 0;

    queue1.forEach((num) => { sum1 += num; });
    queue2.forEach((num) => { sum2 += num; });
    
    while (sum1 !== sum2) {
        if (index1 === total || index2 === total)
            return -1;
        if (sum1 > sum2) {
            sum1 -= queue1[index1];
            sum2 += queue1[index1];
            queue2.push(queue1[index1]);
            index1++;
        } else if (sum1 < sum2) {
            sum2 -= queue2[index2];
            sum1 += queue2[index2];
            queue1.push(queue2[index2]);
            index2++;
        }
        answer++;
    }
    
    return answer;
}
