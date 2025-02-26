function solution(n, w, num) {
    var answer = 0;
    
    const targetY = Math.ceil(num/w); // 꺼내려는 상자의 y 위치
    // const targetX = targetY % 2 === 1 ? (num%w === 0 ? 1 : num%w) : (w - num%w + 1) % w; // 꺼내려는 상자의 x 위치
    
    const temp = num%w === 0 ? w : num%w;
    let targetX = targetY % 2 === 0 ? w - temp + 1 : temp;
    
    // 꺼래려는 상자의 x 위치가 똑같은 가장 높은 상자의 y 위치 구하기
    let currentY = targetY;
    let currentNum = num;
    let nextNum = currentNum + (currentY % 2 === 0 ? targetX : (w - targetX + 1)) * 2 - 1;
    while (nextNum <= n) {
        currentNum = nextNum;
        currentY++;
        nextNum += (currentY % 2 === 0 ? targetX : (w - targetX + 1)) * 2 - 1;
    }
    
    return currentY - targetY + 1;
}