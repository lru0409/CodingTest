function solution(n, info) {
    
    let maxScoreDiff = 0;
    let answer = [];
    
    const check = function(arrowCounts) {  
        let myScore = 0, opponentScore = 0;
        for (let i = 0; i < 11; i++) {
            if (info[i] === 0 && arrowCounts[i] === 0) continue;
            if (info[i] < arrowCounts[i]) myScore += (10 - i);
            else opponentScore += (10 - i);
        }
        
        let scoreDiff = myScore - opponentScore;
        if (maxScoreDiff < scoreDiff) {
            maxScoreDiff = scoreDiff;
            answer = arrowCounts.slice();
        } else if (maxScoreDiff === scoreDiff) {
            for (let i = 10; i >= 0; i--) {
                if (arrowCounts[i] < answer[i])
                    break;
                if (arrowCounts[i] > answer[i]) {
                    answer = arrowCounts.slice();
                    break;
                }
            }
        }
    }
    
    const DFS = function(index, remainArrowCount, shotArrowCounts) {
        if (index === 11 || remainArrowCount === 0) {
            if (remainArrowCount > 0) shotArrowCounts[10] += remainArrowCount;
            check(shotArrowCounts);
            return;
        }
        
        // 이 점수 포기하기
        DFS(index + 1, remainArrowCount, shotArrowCounts.slice());
        
        // 이 점수를 얻기 위해 필요한 화살 쏘기
        if (info[index] < remainArrowCount) {
            const newShotArrowCounts = shotArrowCounts.slice();
            newShotArrowCounts[index] = info[index] + 1;
            DFS(index + 1, remainArrowCount - newShotArrowCounts[index], newShotArrowCounts);
        }
    }
    
    DFS(0, n, Array(11).fill(0));
    
    if (maxScoreDiff === 0)
        return [-1];
    return answer;
}