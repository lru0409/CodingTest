#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, vector<vector<int>>& graph)
{
    queue<pair<int, int>> Q; // 노드, 거리
    vector<bool> visited(n + 1);
    int max_dist = 0, answer = 0;
    
    Q.push(make_pair(1, 0));
    visited[1] = true;
    
    while (!Q.empty())
    {
        int cur = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        
        if (max_dist < dist) {
            max_dist = dist;
            answer = 0;
        }
        if (max_dist <= dist)
            answer += 1;
        
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (visited[next])
                continue;
            visited[next] = true;
            Q.push(make_pair(next, dist + 1));
        }
    }
    return answer;
}

int solution(int n, vector<vector<int>> edge)
{
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    int answer = BFS(n, graph);
    
    return answer;
}