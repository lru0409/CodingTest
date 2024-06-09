function solution(order) {
    
    let answer = 0;
    let main = 1;
    const sub = []; // 보조 컨테이너 벨트
    
    for (let i = 0; i < order.length; i++) {
        
        if (sub.length && order[i] === sub[sub.length - 1]) {
            sub.pop();
            answer++;
            continue;
        }
        
        while (main <= order.length && main <= order[i]) {
            if (main === order[i]) {
                answer++;
                break;
            }
            sub.push(main);
            main++;
        }
        
        if (main > order.length || main > order[i])
            break;

        main++;
    }
    
    return answer;
}