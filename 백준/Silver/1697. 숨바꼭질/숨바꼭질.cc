#include <iostream>
#include <queue>
using namespace std;

int visited[100001] = {false, };

void BFS(int N, int K)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(N, 0));

	while (!Q.empty())
	{
		int X = Q.front().first;
		int count = Q.front().second;
		Q.pop();

		if (X == K)
		{
			cout << count << endl;
			break;
		}

		if (X - 1 >= 0 && !visited[X - 1]) {
			visited[X - 1] = true;
			Q.push(make_pair(X - 1, count + 1));
		}

		if (X + 1 <= 100000 && !visited[X + 1]) {
			visited[X + 1] = true;
			Q.push(make_pair(X + 1, count + 1));
		}

		if (X * 2 <= 100000 && !visited[X * 2]) {
			visited[X * 2] = true;
			Q.push(make_pair(X * 2, count + 1));
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	BFS(N, K);

	return (0);
}