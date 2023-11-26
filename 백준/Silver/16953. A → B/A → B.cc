#include <iostream>
#include <queue>
using namespace std;

int BFS(int  A, int B)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(A, 0));

	while (!Q.empty())
	{
		long long num = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (num == B)
			return (cnt + 1);
		if (num * 2 <= B)
			Q.push(make_pair(num * 2, cnt + 1));
		if (num * 10 + 1 <= B)
			Q.push(make_pair(num * 10 + 1, cnt + 1));
	}
	return (-1);
}

int main()
{
	int A, B;
	cin >> A >> B;
	cout << BFS(A, B) << endl;

	return (0);
}