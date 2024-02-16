#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int V;
vector<pair<int, int> > tree[MAX]; // 각 정점에 대해 연결된 노드, 가중치
int furthest_dist = 0;
int furthest_node;

// 특정 노드부터 가장 먼 노드와 그 거리 구하기
void DFS(int cur, int prev, int dist)
{
	if (dist > furthest_dist)
	{
		furthest_dist = dist;
		furthest_node = cur;
	}

	for(size_t i = 0; i < tree[cur].size(); i++)
	{
		if (tree[cur][i].first != prev)
			DFS(tree[cur][i].first, cur, dist + tree[cur][i].second);
	}
}

int main(void)
{
	int parent, child, weight;

	cin >> V;
	for(int i = 0; i < V; i++)
	{
		cin >> parent;
		while (true)
		{
			cin >> child;
			if (child == -1) break;
			cin >> weight;
			
			tree[parent].push_back(make_pair(child, weight));
		}
	}

	DFS(1, 0, 0);
	DFS(furthest_node, 0, 0);
	cout << furthest_dist << '\n';

	return 0;
}