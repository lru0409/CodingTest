function solution(cards) {
    
    const visited = new Array(cards.length).fill(false);
    const boxCounts = [];
    
    for (let i = 0; i < cards.length; i++) {
        if (visited[i])
            continue;
        let count = 0;
        let card = cards[i];
        while (!visited[card - 1]) {
            visited[card - 1] = true;
            count++;
            card = cards[card - 1];
        }
        boxCounts.push(count);
    }
    
    if (boxCounts.length <= 1)
        return 0;   
    boxCounts.sort((a, b) => b - a);
    return boxCounts[0] * boxCounts[1];
}