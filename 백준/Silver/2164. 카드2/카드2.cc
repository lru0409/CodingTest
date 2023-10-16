#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> Q;
	for(int i = 1; i <= N; i++)
		Q.push(i);
	
	while (Q.size() > 1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front() << endl;

	return 0;
}