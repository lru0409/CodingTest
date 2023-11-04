#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> network[101];

int BFS(int com)
{
	queue<int> Q;
	Q.push(com);
	bool visited[101] = { false, };
	visited[com] = true;

	int count = 0;
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for(int i = 0; i < network[cur].size(); i++)
		{
			int next = network[cur][i];
			if (visited[next]) continue;
			count += 1;
			Q.push(next);
			visited[next] = true;
		}
	}
	return (count);
}

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int com1, com2;
		cin >> com1 >> com2;
		network[com1].push_back(com2);
		network[com2].push_back(com1);
	}
	cout << BFS(1);
	return (0);
}