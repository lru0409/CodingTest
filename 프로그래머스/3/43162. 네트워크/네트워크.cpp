#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
    
        queue<int> Q;
        Q.push(i);
        visited[i] = true;
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for(int j = 0; j < n; j++)
            {
                if (visited[j] || computers[cur][j] == 0)
                    continue;
                visited[j] = true;
                Q.push(j);
            }   
        }
        answer += 1;
    }
    
    return answer;
}