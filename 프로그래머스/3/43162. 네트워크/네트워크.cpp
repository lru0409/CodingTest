#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, vector<bool>& visited, int n, vector<vector<int>>& computers)
{
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for(int i = 0; i < n; i++)
        {
            if (visited[i] || computers[cur][i] == 0)
                continue;
            visited[i] = true;
            Q.push(i);
        }   
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        BFS(i, visited, n, computers);
        answer += 1;
    }
    
    return answer;
}