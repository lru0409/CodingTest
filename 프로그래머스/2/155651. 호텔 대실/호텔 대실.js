function solution(book_time) {
    
    book_time.sort();
    const rooms = []; // 현재 사용 중인 룸들이 사용 가능해지는 시간
    
    const plusTenMin = function(time) {
        let [newHour, newMinute] = time;
        newHour += Math.floor((newMinute + 10) / 60);
        newMinute = (newMinute + 10) % 60;
        return [newHour, newMinute];
    }
    
    // 기존 룸으로 가능할 시 룸 인덱스, 불가능할 시 -1 반환
    const findAvailableRoom = function(checkInTime) {
        for(let i = 0; i < rooms.length; i++) {
            const [roomHour, roomMin] = rooms[i];
            const [checkInHour, checkInMin] = checkInTime;
            if (roomHour < checkInHour ||
                roomHour === checkInHour && roomMin <= checkInMin)
                return i;
        }
        return -1;
    }
    
    for(let time of book_time) {
        const [checkIn, checkOut] = time.map((timeStr) => timeStr.split(':').map(Number));
        let roomIndex = findAvailableRoom(checkIn); // 임실 가능한 룸이 있는지 확인
        if (roomIndex === -1) { // 입실 가능한 룸 없음 -> 새로운 룸 사용
            rooms.push(plusTenMin(checkOut));
        } else { // 입실 가능한 룸 있음 -> roomIndex의 룸 사용
            rooms[roomIndex] = plusTenMin(checkOut);
        }
    }
    
    return rooms.length;
}