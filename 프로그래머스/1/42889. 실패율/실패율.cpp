#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, float> stage1, pair<int, float> stage2)
{
    if (stage1.second != stage2.second)
        return stage1.second > stage2.second;
    return stage1.first < stage2.first;
}

vector<int> solution(int N, vector<int> stages)
{
    sort(stages.begin(), stages.end());
    
    vector<pair<int, float> > fail; // 스테이지 당 실패율
    int reached = stages.size();
    int stage = 1, index = 0;
    while (stage <= N)
    {
        int not_cleared = 0;
        while (index < stages.size() && stages[index] == stage) {
            not_cleared++;
            index++;
        }
        if (reached == 0)
            fail.push_back({stage, 0});
        else
            fail.push_back({stage, (float)not_cleared/reached});
        reached -= not_cleared;
        stage++;
    }
    
    sort(fail.begin(), fail.end(), comp);

    vector<int> answer(N);
    for(int i = 0; i < N; i++)
        answer[i] = fail[i].first;

    return answer;
}