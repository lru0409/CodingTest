#include <iostream>
using namespace std;

int N, S;
int input[20];
int combination[20];
bool visited[20] = { false, };
int result = 0;

void DFS(int depth, int len, int next)
{
	if (depth == len)
	{
		int sum = 0;
		for(int i = 0; i < len; i++) sum += combination[i];
		if (sum == S) {
			result++;
		}
		return ;
	}
	for(int i = next; i < N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		combination[depth] = input[i];
		DFS(depth + 1, len, i + 1);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> N >> S;
	for(int i = 0; i < N; i++) cin >> input[i];

	for(int i = 1; i <= N; i++)
	{
		DFS(0, i, 0);
	}
	cout << result << endl;

	return (0);
}