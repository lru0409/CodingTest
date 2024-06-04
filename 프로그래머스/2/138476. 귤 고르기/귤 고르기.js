function solution(k, tangerine) {
    
    const countPerSize = new Array(10000001).fill(0);
    
    for (let i = 0; i < tangerine.length; i++) {
        countPerSize[tangerine[i]] += 1;
    }
    
    countPerSize.sort((a, b) => b - a);
    
    let type_idx = 0;
    while (k > 0) {
        k -= countPerSize[type_idx++];
    }

    return type_idx;
}