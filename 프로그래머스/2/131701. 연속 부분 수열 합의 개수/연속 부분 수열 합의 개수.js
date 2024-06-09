function solution(elements) {
    
    const circular = elements.concat(elements);
    const sumSet = new Set();
    
    for (let len = 1; len <= elements.length; len++) {
        for (let i = 0; i < elements.length; i++) {
            let sum = 0;
            for (let j = i; j < i + len; j++)
                sum += circular[j];
            sumSet.add(sum);
        }
    }
        
    return sumSet.size;
}