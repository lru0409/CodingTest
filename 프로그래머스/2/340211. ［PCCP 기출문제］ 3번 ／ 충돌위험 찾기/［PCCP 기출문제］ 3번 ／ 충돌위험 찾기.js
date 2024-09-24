function getPos(points, num) {
    return points[num - 1].slice();
}

function detectEmergency(robots) {
    const posMap = {};
    robots.forEach((robot) => { // 100
        const posString = robot.pos.toString();
        posMap[posString] = posMap[posString] ? posMap[posString] + 1 : 1;
    });
    return Object.values(posMap).reduce((totalCount, count) => { // 100
        totalCount = count > 1 ? totalCount + 1 : totalCount;
        return totalCount 
    }, 0);
}

function solution(points, routes) {
    let robots = [];
    routes.forEach((route) => { // 100
        robots.push({
            pos: getPos(points, route.shift()),
            route: route.map((num) => getPos(points, num)),
        });
    });

    let count = detectEmergency(robots); // 위험 상황 발생 횟수

    while (robots.length) { // 20000
        // 로봇 이동 100
        for (robot of robots) {
            // r 좌표가 다르다면 r부터, 아니면 c부터
            const [cy, cx] = robot.pos;
            const [ty, tx] = robot.route[0];
            if (cy !== ty) {
                robot.pos[0] = cy < ty ? cy + 1 : cy - 1;
            } else if (cx !== tx) {
                robot.pos[1] = cx < tx ? cx + 1 : cx - 1;
            }
        }
        
        count += detectEmergency(robots);
        
        // 포인트에 도달한 로봇은 경로 업데이트 or 제거 100
        robots = robots.filter(({ pos, route }) => {
            if (pos[0] !== route[0][0]) return true;
            if (pos[1] !== route[0][1]) return true;
            if (route.length > 1) {
                route.shift();
                return true;
            }
            return false;
        });
    }
    
    return count;
}