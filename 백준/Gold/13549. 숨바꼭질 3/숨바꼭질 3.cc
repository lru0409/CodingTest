#include <iostream>
#include <deque>
using namespace std;

void BFS(int N, int K)
{
	deque<pair<int, int> > DQ; // 위치, 걸린 시간
	bool visited[100001] = { false, };

	DQ.push_back(make_pair(N, 0));
	visited[N] = true;

	while (!DQ.empty())
	{
		int pos = DQ.front().first;
		int time = DQ.front().second;
		DQ.pop_front();
		
		if (pos == K) {
			cout << time << '\n';
			return;
		}

		if (pos * 2 <= 100000 && !visited[pos * 2])
		{
			DQ.push_front(make_pair(pos * 2, time));
			visited[pos * 2] = true;
		}
		if (pos - 1 >= 0 && !visited[pos - 1])
		{
			DQ.push_back(make_pair(pos - 1, time + 1));
			visited[pos - 1] = true;
		}
		if (pos + 1 <= 100000 && !visited[pos + 1])
		{
			DQ.push_back(make_pair(pos + 1, time + 1));
			visited[pos + 1] = true;
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
