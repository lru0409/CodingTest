function solution(cap, n, deliveries, pickups) {
    while (deliveries[n-1] === 0 && pickups[n-1] === 0) {
        deliveries.pop();
        pickups.pop();
        n--;
    }
    
    let answer = 0;
    while (deliveries.length || pickups.length) {
        answer += Math.max(deliveries.length, pickups.length) * 2;
        let count = 0;
        while (deliveries.length) {
            count += deliveries.pop();
            if (cap < count) {
                deliveries.push(count - cap);
                break;
            }
        }
        count = 0;
        while (pickups.length) {
            count += pickups.pop();
            if (cap < count) {
                pickups.push(count - cap);
                break;
            }
        }
    }
    
    return answer;
}