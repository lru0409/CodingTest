function solution(n, info) {
    
    let maxScoreDiff = 0;
    let answer = [];
    
    const check = function(arrowCounts) {  
        let myScore = 0, opponentScore = 0;
        let myTotalCount = 0;
        for (let i = 0; i < 11; i++) {
            if (info[i] === 0 && arrowCounts[i] === 0)
                continue;
            if (info[i] < arrowCounts[i])
                myScore += (10 - i);
            else
                opponentScore += (10 - i);
            myTotalCount += arrowCounts[i];
        }
        if (maxScoreDiff <= myScore - opponentScore) {
            maxScoreDiff = myScore - opponentScore;
            if (myTotalCount < n)
                arrowCounts[10] = n - myTotalCount;
            answer = arrowCounts;
        }
    }
    
    const DFS = function(shotArrowCounts, remainArrowCount) {
        if (shotArrowCounts.length === 11) {
            check(shotArrowCounts);
            return;
        }
        const opponentArrowCount = info[shotArrowCounts.length];
        if (opponentArrowCount < remainArrowCount) {
            const newShotArrowCount = [...shotArrowCounts, opponentArrowCount + 1];
            DFS(newShotArrowCount, remainArrowCount - opponentArrowCount - 1);
        }
        DFS([...shotArrowCounts, 0], remainArrowCount);
    }
    
    DFS([], n);
    
    if (maxScoreDiff === 0)
        return [-1];
    return answer;
}