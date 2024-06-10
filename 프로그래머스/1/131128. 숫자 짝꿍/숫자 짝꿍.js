function solution(X, Y) {

    const setMap = function(numStr) {
        const map = new Map();
        for (c of numStr) {
            if (map.has(c)) {
                map.set(c, map.get(c) + 1);
            } else {
                map.set(c, 1);
            }
        }
        return map;
    }
    
    const mapX = setMap(X);
    const mapY = setMap(Y);
    
    const parteners = [];
    
    mapX.forEach((value, key) => {
        if (mapY.has(key)) {
            const count = Math.min(value, mapY.get(key));
            for (let i = 0; i < count; i++)
                parteners.push(key);
        }
    })
    
    if (parteners.length === 0)
        return '-1';
    parteners.sort((a, b) => b - a);
    if (parteners[0] === '0')
        return '0';
    return parteners.join('');
}