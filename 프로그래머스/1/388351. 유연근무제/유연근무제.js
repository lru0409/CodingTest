function solution(schedules, timelogs, startday) {
    var answer = 0;
    
    const convertToRealTime = (time) => {
        const hour = Math.floor(time / 100);
        const minute = time % 100;
        return hour * 60 + minute;
    }
    
    // 직원 순회
    for (let employee = 0; employee < schedules.length; employee++) {
        const schedule = convertToRealTime(schedules[employee]);
        // 직원 당 요일 순회
        let lateness = false;
        for (let dayCount = 0; dayCount < 7; dayCount++) {
            if (5 <= ((startday - 1) + dayCount) % 7) continue;
            const timelog = convertToRealTime(timelogs[employee][dayCount]);
            if (schedule + 10 < timelog) {
                lateness = true;
                break;
            }
        }
        if (!lateness) answer++;
    }
    
    return answer;
}