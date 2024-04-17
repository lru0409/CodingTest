#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define S 0
#define E 1

int solution(vector<vector<int>> targets)
{
    sort(targets.begin(), targets.end());
    
    vector<int> cur = { targets[0][S], targets[0][E] };
    int answer = 1;
    for(int i = 1; i < targets.size(); i++)
    {
        vector<int> tg = targets[i];
        
        if ((cur[S] < tg[S] && tg[S] < cur[E]) ||
            tg[S] < cur[E] && cur[E] < tg[E])
        {
            cur[S] = max(cur[S], tg[S]);
            cur[E] = min(cur[E], tg[E]);
        }
        else
        {
            answer += 1;
            cur = tg;   
        }
    }
    
    return answer;
}