#include <string>
#include <vector>

#define IMPOSSIBLE 9

using namespace std;

vector<int> pm;
vector<bool> visited(8, false);
int answer = IMPOSSIBLE;

int wallCheck(int n, vector<int> weak, int weak_start)
{
    int current = weak[weak_start];
    int weak_idx = weak_start;
    int pm_idx = 0;
    while(pm_idx < pm.size())
    {
        int prev = current;
        current = (current + pm[pm_idx++]) % n;
        while(true)
        {
            if (prev < current && 
                (weak[weak_idx] < prev || current < weak[weak_idx]))
                break;
            if (current < prev && 
               weak[weak_idx] < prev && current < weak[weak_idx])
                break;
            weak_idx = (weak_idx + 1) % weak.size();
            if (weak_idx == weak_start)
                return pm_idx;
        }
        current = weak[weak_idx];        
    }
    return IMPOSSIBLE;
}

void permutation(int n, vector<int> weak, vector<int> dist)
{
    if (pm.size() == dist.size())
    {
        for(int i = 0; i < weak.size(); i++)
            answer = min(answer, wallCheck(n, weak, i));
        return;
    }
    
    for(int i = 0; i < dist.size(); i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        pm.push_back(dist[i]);
        permutation(n, weak, dist);
        pm.pop_back();
        visited[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    permutation(n, weak, dist);
    if (answer == IMPOSSIBLE)
        answer = -1;
    return answer;
}