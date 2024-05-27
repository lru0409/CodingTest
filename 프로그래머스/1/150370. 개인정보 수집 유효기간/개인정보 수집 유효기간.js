function solution(today, terms, privacies) {
    
    const getDays = function(date) {
        date = date.split('.').map(Number);
        return ((date[0] - 2000) * 12 + date[1]) * 28 + date[2]; 
    }
    
    const todayDays = getDays(today);
    const termsMap = new Map();
    for(term of terms) {
        term = term.split(' ');
        termsMap.set(term[0], parseInt(term[1]) * 28);
    }
    
    var answer = [];
    for (let i = 0; i < privacies.length; i++) {
        const privacy = privacies[i].split(' ');
        const privacyDays = getDays(privacy[0]) + termsMap.get(privacy[1]);
        if (privacyDays <= todayDays)
            answer.push(i + 1);
    }
    
    return answer;
}