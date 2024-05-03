#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int input;
	priority_queue<int, vector<int>, greater<int> > PQ;
	for(int i = 0; i < N; i++) {
		cin >> input;
		PQ.push(input);
	}

	int answer = 0;
	while (PQ.size() > 1)
	{
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();
		PQ.push(a + b);
		answer += a + b;
	}
	cout << answer << '\n';

	return 0;
}