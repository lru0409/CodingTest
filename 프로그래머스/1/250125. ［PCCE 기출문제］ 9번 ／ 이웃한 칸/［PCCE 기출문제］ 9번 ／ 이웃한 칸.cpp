#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w)
{
    int dh[4] = { 0, 0, -1, 1 };
    int dw[4] = { -1, 1, 0, 0 };
    int answer = 0;
    
    for(int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nw < 0 || nh >= board.size() || nw >= board.size())
            continue;
        if (board[h][w] == board[nh][nw])
            answer += 1;
    }
    
    return answer;
}