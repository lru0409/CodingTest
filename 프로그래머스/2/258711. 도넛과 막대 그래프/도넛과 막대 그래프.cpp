#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1000001

#define DONUT 1  // 도넛 모양
#define LINE 2   // 막대 모양
#define EIGHT 3  // 8자 모양

int max_point = 0;
vector<vector<int>> graph(MAX);
vector<int> out_degree(MAX, 0);
vector<int> in_degree(MAX, 0);
vector<bool> visited(MAX, false);

vector<int> answer(4, 0); // 생성된 정점, 도넛, 막대, 8자 모양 그래프 개수

void DFS(int node)
{
    if (visited[node]) { answer[DONUT]++; return; }
    if (out_degree[node] == 2) { answer[EIGHT]++; return; }
    if (out_degree[node] == 0) { answer[LINE]++; return; }
    visited[node] = true;
    
    for(int i = 0; i < graph[node].size(); i++)
        DFS(graph[node][i]);
}

vector<int> solution(vector<vector<int>> edges)
{
    // 그래프, 진입/진출 차수 세팅
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        out_degree[edges[i][0]] += 1;
        in_degree[edges[i][1]] += 1;
        max_point = max(max_point, max(edges[i][0], edges[i][1]));
    }
    
    // 생성된 정점 찾기 (생성된 정점은 진입 차수가 없고, 진출 차수가 2 이상)
    for(int i = 1; i <= max_point; i++) {
        if (in_degree[i] == 0 && out_degree[i] >= 2) {
            answer[0] = i;
            break;
        }
    }
    
    // 생성된 정점이 가리키는 정점이, 어떤 모양의 그래프에 속해있는가?
    for(int i = 0; i < graph[answer[0]].size(); i++)
        DFS(graph[answer[0]][i]);
    
    return answer;
}