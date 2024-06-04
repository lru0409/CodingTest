function solution(n, k, enemy) {
    
    let start = 0;
    let end = enemy.length - 1;
    
    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        // k개의 무적권, n명의 병사로 mid 라운드를 해치울 수 있는가?
        const tmp_enemy = enemy.slice(0, mid + 1);
        let tmp_n = n;
        tmp_enemy.sort((a, b) => a - b);
        let i = 0;
        for (i; i < tmp_enemy.length - k; i++) {
            tmp_n -= tmp_enemy[i];
            if (tmp_n < 0)
                break;
        }
        if (i < tmp_enemy.length - k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return (end + 1);
}
