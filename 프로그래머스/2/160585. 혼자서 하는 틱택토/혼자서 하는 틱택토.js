function solution(board) {
    
    const getCount = function(player) {
        let count = 0;
        for(line of board) {
            for(char of line) {
                if (char == player)
                    count++;
            }
        }
        return count;
    }

    const getIsWin = function(player) {
        for(let i = 0; i < 3; i++) {
            if (player === board[i][0] && // 가로 검사
                player === board[i][1] &&
                player === board[i][2])
                return true;
            if (player === board[0][i] && // 세로 검사
                player === board[1][i] &&
                player === board[2][i])
                return true;
        }
        // 대각선 두 줄 검사
        if (player === board[0][0] &&
            player === board[1][1] &&
            player === board[2][2])
            return true;
        if (player === board[0][2] &&
            player === board[1][1] &&
            player === board[2][0])
            return true;   
    }
    
    const oCount = getCount('O');
    const oIsWin = getIsWin('O');
    const xCount = getCount('X');
    const xIsWin = getIsWin('X');

    if (oCount !== xCount && oCount !== xCount + 1) // 무조건 'O = X' or 'O = X+1' 여야 함
        return 0;
    if (xIsWin === true && oCount !== xCount) // X가 이긴 경우에는 'O = X' 여야 함
        return 0;
    if (oIsWin === true && oCount !== xCount + 1) // O가 이긴 경우에는 'O = X+1' 여야 함
        return 0;

    return 1;
}

// 1. 둘 다 이미 이긴 상황
// 2. X가 이겼는데 O가 더 놓은 상황 (O > X)
// 3. O가 이겼는데 X가 더 놓은 상황 (O == X)
// 4. 아무도 이기지 않은 경우 O, X의 개수가 같거나 / O가 하나 더 많아야 함