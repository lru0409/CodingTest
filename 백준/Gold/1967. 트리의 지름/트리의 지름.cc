#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001

int n; // 노드의 개수
vector<pair<int, int> > tree[MAX]; // 각 노드 마다의 <연결된 노드, 가중치> 벡터

void Input()
{
	cin >> n;
	int p, c, w;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> p >> c >> w; // 부모, 자식, 가중치
		tree[p].push_back(make_pair(c, w));
		tree[c].push_back(make_pair(p, w));
	}
}

int max_dist = 0;
int furthest_node;
bool visited[MAX];

void DFS(int node, int dist)
{
	if (dist > max_dist)
	{
		max_dist = dist;
		furthest_node = node;
	}

	for(size_t i = 0; i < tree[node].size(); i++)
	{
		if (visited[tree[node][i].first]) continue;
		visited[tree[node][i].first] = true;
		DFS(tree[node][i].first, dist + tree[node][i].second);
		visited[tree[node][i].first] = false;
	}
}

void Solve()
{
	// 루트 노드에서 가장 먼 노드 찾기
	visited[1] = true;
	DFS(1, 0);
	visited[1] = false;
	max_dist = 0;

	// 찾은 노드에서 가장 먼 노드 찾기
	visited[furthest_node] = true;
	DFS(furthest_node, 0);
	cout << max_dist << '\n';
}

int main()
{
	Input();
	Solve();

	return (0);
}