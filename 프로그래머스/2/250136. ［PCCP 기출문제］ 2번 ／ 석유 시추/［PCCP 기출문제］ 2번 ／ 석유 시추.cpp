#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 500
#define START 0
#define END 1
#define AMOUNT 2

using namespace std;

int n, m;

vector<int> BFS(int x, int y, const vector<vector<int>>& land, vector<vector<bool>>& visited)
{
    vector<int> result(3, 0); // 시작 x위치, 끝 x위치, 석유량
    result[0] = MAX;

    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    visited[y][x] = true;
    
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    
    while (!Q.empty())
    {
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();
        
        result[START] = min(result[0], cx);
        result[END] = max(result[1], cx);
        result[AMOUNT] += 1;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (visited[ny][nx] || land[ny][nx] != 1)
                continue;
            visited[ny][nx] = true;
            Q.push(make_pair(nx, ny));
        }
    }
    return result;
}

int solution(vector<vector<int>> land)
{
    n = land.size();
    m = land[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> amounts(m, 0); // 각 위치에서 뽑을 수 있는 석유량

    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            if (visited[i][j] || land[i][j] != 1)
                continue;

            vector<int> oil_bundle = BFS(j, i, land, visited);
            for(int k = oil_bundle[START]; k <= oil_bundle[END]; k++)
                amounts[k] += oil_bundle[AMOUNT]; 
        }
    }
    
    int answer = 0;
    for(int i = 0; i < m; i++)
        answer = max(answer, amounts[i]);
        
    return answer;
}