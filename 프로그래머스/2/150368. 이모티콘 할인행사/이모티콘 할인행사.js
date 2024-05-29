function solution(users, emoticons) {
    
    let resultJoinCount = 0;
    let resultSaleAmount = 0;
    
    const discountRates = [10, 20, 30, 40];
    const discounts = new Array(emoticons.length);
    
    const checkCases = function() {
        let joinCount = 0;
        let saleAmount = 0;
        const prices = emoticons.map((price, index) => price * (100 - discounts[index])/100);

        for ([standard, joinPrice] of users) {
            let total = 0;
            for (let i = 0; i < discounts.length; i++) {
                if (standard <= discounts[i])
                    total += prices[i];
            }
            if (joinPrice <= total) {
                joinCount += 1;   
            } else {
                saleAmount += total;   
            }
        }
        
        if (resultJoinCount < joinCount ||
            (resultJoinCount === joinCount && resultSaleAmount < saleAmount))
        {
            resultJoinCount = joinCount;
            resultSaleAmount = saleAmount;
        }
    }

    const CheckDiscountCombinations = function(depth) {
        if (depth === emoticons.length) {
            checkCases();
            return;
        }
        for (rate of discountRates) {
            discounts[depth] = rate;
            CheckDiscountCombinations(depth + 1);
        }
    }
    
    CheckDiscountCombinations(0);
    
    var answer = [resultJoinCount, resultSaleAmount];
    return answer;
}