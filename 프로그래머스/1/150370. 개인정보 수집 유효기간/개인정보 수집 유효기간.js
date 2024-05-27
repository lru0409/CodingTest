function solution(today, terms, privacies) {
    
    const getDays = function(date) {
        const [year, month, day] = date.split('.').map(Number);
        date = date.split('.').map(Number);
        return (year * 12 + month) * 28 + day; 
    }
    
    const todayDays = getDays(today);
    const termsMap = new Map();
    for(term of terms) {
        const [kind, year] = term.split(' ');
        termsMap.set(kind, parseInt(year) * 28);
    }
    
    var answer = [];
    for (let i = 0; i < privacies.length; i++) {
        const [date, kind] = privacies[i].split(' ');
        const privacyDays = getDays(date) + termsMap.get(kind);
        if (privacyDays <= todayDays)
            answer.push(i + 1);
    }
    
    return answer;
}