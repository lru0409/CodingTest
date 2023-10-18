#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int N, M, importance;
	for(int i = 0; i < T; i++)
	{
		queue< pair<int, int> > Q;
		priority_queue<int> PQ;

		cin >> N >> M;
		for(int i = 0; i < N; i++)
		{
			cin >> importance;
			Q.push(make_pair(i, importance));
			PQ.push(importance);
		}

		int count = 0;
		while (!Q.empty())
		{
			if (Q.front().second == PQ.top())
			{
				count += 1;
				if (Q.front().first == M)
				{
					cout << count << endl;
					break;
				}
				Q.pop( );
				PQ.pop();
			}
			else
			{
				Q.push(Q.front());
				Q.pop();
			}
		}
	}
}
