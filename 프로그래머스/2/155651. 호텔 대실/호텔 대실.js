function solution(book_time) {
    
    book_time.sort();
    const rooms = []; // 현재 사용 중인 룸들이 사용 가능해지는 시간
    
    const plusTenMin = function(time) {
        const newTime = [ ...time ];
        newTime[1] += 10;
        if (newTime[1] >= 60) {
            newTime[1] %= 60;
            newTime[0] += 1;
        }
        return newTime;
    }
    
    // 기존 룸으로 가능할 시 룸 인덱스, 불가능할 시 -1 반환
    const checkRooms = function(time) {
        for(let i = 0; i < rooms.length; i++) {
            if (rooms[i][0] < time[0] ||
                (rooms[i][0] === time[0] && rooms[i][1] <= time[1]))
                return i;
        }
        return -1;
    }
    
    for(let time of book_time) {
        time = time.map((timeStr) => { // ["시:분", "시,분"] => [[시,분][시,분]]
            return timeStr.split(':').map((numStr) => parseInt(numStr));
        })
        let roomIndex = checkRooms(time[0]); // 임실 가능한 룸이 있는지 확인
        if (roomIndex === -1) { // 입실 가능한 룸 없음 -> 새로운 룸 사용
            rooms.push(plusTenMin(time[1]));
        } else { // 입실 가능한 룸 있음 -> roomIndex의 룸 사용
            rooms[roomIndex] = plusTenMin(time[1]);
        }
    }
    
    return rooms.length;
}