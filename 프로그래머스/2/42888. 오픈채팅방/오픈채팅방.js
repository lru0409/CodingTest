function solution(record) {
    const nicknameMap = {};
    record.forEach((str) => {
        const [type, uid, nickname] = str.split(" ");
        if (type === "Enter" || type === "Change") {
            nicknameMap[uid] = nickname;
        }
    });
    
    const answer = [];
    record.forEach((str) => {
        const [type, uid] = str.split(" ");
        if (type === "Enter") {
            answer.push(`${nicknameMap[uid]}님이 들어왔습니다.`);
        } else if (type === "Leave") {
            answer.push(`${nicknameMap[uid]}님이 나갔습니다.`);
        }
    });
    
    return answer;
}
