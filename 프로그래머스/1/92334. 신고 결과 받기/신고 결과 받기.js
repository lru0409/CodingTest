function solution(id_list, report, k) {
    const reportMap = new Map(); // 각 유저마다, 해당 유저를 신고한 유저들
    const mailMap = new Map(); // 각 유저마다, 메일 수신 횟수
    for (const id of id_list) {
        reportMap.set(id, []);
        mailMap.set(id, 0);
    }
    
    for (let i = 0; i < report.length; i++) {
        const [reportUser, reportedUser] = report[i].split(' ');
        const reportUserList = reportMap.get(reportedUser);
        if (reportUserList.includes(reportUser))
            continue;
        reportUserList.push(reportUser);
        reportMap.set(reportedUser, reportUserList);
    }
    
    for (const [key, value] of reportMap) {
        if (value.length < k) continue;
        value.forEach((user) => { mailMap.set(user, mailMap.get(user) + 1); });
    }
    
    return [...mailMap.values()];
}