#include <iostream>
#include <queue>
using namespace std;

int N;
int graph[100][100] = {0};
int result[100][100] = {0};

void BFS(int point)
{
	queue<int> Q;
	Q.push(point);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < N; i++)
		{
			if (result[point][i])
				continue;
			if (graph[cur][i])
			{
				Q.push(i);
				result[point][i] = 1;
			}
		}
	}
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> graph[i][j];
	
	for(int i = 0; i < N; i++)
		BFS(i);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cout << result[i][j] << ' ';
		cout << endl;
	}

	return (0);
}