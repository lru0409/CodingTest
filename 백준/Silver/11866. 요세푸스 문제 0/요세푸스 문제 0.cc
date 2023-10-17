#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> people;
	for(int i = 1; i <= N; i++)
		people.push(i);
	
	cout << '<';
	while (!people.empty())
	{
		for(int i = 1; i < K; i++)
		{
			people.push(people.front());
			people.pop();
		}
		cout << people.front();
		if (people.size() > 1) cout << ", ";
		people.pop();
	}
	cout << '>';

	return 0;
}