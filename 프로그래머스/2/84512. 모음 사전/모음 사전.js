function solution(word) {
    const alphabets = ['A', 'E', 'I', 'O', 'U'];
    let count = 0;
    
    const permutation = (p) => {
        if (p.join("") === word) return count;
        if (p.length === 5) return undefined;
        for (let i = 0; i < 5; i++) {
            p.push(alphabets[i]);
            count++;
            const ret = permutation(p);
            if (ret !== undefined) return ret;
            p.pop();
        }
        return undefined;
    }
    
    return permutation([]);
}