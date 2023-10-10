#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int input[13];
int print[6];
bool visited[13] = { false, };

void combination(int depth, int next)
{
	if (depth == 6)
	{
		for(int i = 0; i < 6; i++)
			cout << print[i] << " ";
		cout << endl;
		return ;
	}
	for(int i = next; i < K; i++)
	{
		if (visited[i]) continue;
		print[depth] = input[i];
		visited[i] = true;
		combination(depth + 1, i + 1);
		visited[i] = false;
	}
}

int main()
{
	while (true)
	{
		cin >> K;
		if (K == 0) break;
		for(int i = 0; i < K; i++)
			cin >> input[i];
		sort(input, input + K);
		combination(0, 0);
		cout << endl;
	}

	return 0;
}