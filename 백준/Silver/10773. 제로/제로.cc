#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int K;
	cin >> K;

	stack<int> S;
	int input;
	for(int i = 0; i < K; i++)
	{
		cin >> input;
		if (input == 0) S.pop();
		else S.push(input);
	}

	int sum = 0;
	while (!S.empty())
	{
		sum += S.top();
		S.pop();
	}
	cout << sum << endl;

	return (0);
}