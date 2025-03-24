function solution(price, money, count) {
    let cnt = 1;
    while (cnt <= count) {
        money -= price * cnt;
        cnt++;
    }
    return money < 0 ? Math.abs(money) : 0;
}