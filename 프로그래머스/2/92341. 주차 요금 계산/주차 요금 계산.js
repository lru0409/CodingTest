function solution(fees, records) {
    
    const defaultTime = fees[0];
    const defaultFee = fees[1];
    const unitTime = fees[2];
    const unitFee = fees[3];
    
    const totalTimePerCar = new Map();
    const inTimePerCar = new Map();

    const parseTime = function(timeStr) { // "hh:mm" 문자열을 분 단위 정수로 파싱
        const times = timeStr.split(':').map(Number);
        return times[0] * 60 + times[1];
    }

    const addTotalTime = function(carNum, time) {
        if (totalTimePerCar.has(carNum))
            totalTimePerCar.set(carNum, totalTimePerCar.get(carNum) + time);
        else
            totalTimePerCar.set(carNum, time);
    }
    
    for (record of records) {
        const divided = record.split(' ');
        const time = parseTime(divided[0]);
        const carNum = divided[1];
        const type = divided[2];
        
        if (type === 'IN') {
            inTimePerCar.set(carNum, time);
        } else if (type === 'OUT') {
            const inTime = inTimePerCar.get(carNum);
            inTimePerCar.delete(carNum);
            addTotalTime(carNum, time - inTime);
        }
    }
    
    const outTime = parseTime('23:59');
    for (const [carNum, inTime] of inTimePerCar) {
        addTotalTime(carNum, outTime - inTime);
    }
    
    const sortedTotalTime = [...totalTimePerCar.entries()].sort((a, b) => a[0] - b[0]);
    
    const answer = [];
    for (let [carNum, totalTime] of sortedTotalTime) {
        let fee = defaultFee;
        totalTime -= defaultTime;
        if (0 < totalTime) {
            fee += Math.ceil(totalTime / unitTime) * unitFee;
        }
        answer.push(fee);
    }

    return answer;
}