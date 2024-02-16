#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int V;
vector<pair<int, int> > tree[MAX]; // 각 정점에 대해 연결된 노드, 가중치
bool visited[MAX] = { false, };
int furthest_dist = 0;
int furthest_node;

// 특정 노드부터 가장 먼 노드와 그 거리 구하기
void findFurthestNode(int from, int dist)
{
	if (visited[from])
		return;
	visited[from] = true;

	if (dist > furthest_dist)
	{
		furthest_dist = dist;
		furthest_node = from;
	}

	for(size_t i = 0; i < tree[from].size(); i++)
	{
		int to = tree[from][i].first;
		int distance_to = tree[from][i].second;
		findFurthestNode(to, dist + distance_to);
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

	findFurthestNode(1, 0);
	for(int i = 1; i <= V; i++)
		visited[i] = false;
	findFurthestNode(furthest_node, 0);
	cout << furthest_dist << '\n';

	return 0;
}