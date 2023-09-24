#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 8

int N, M;
int input[MAX];
int print[MAX];
int visited[MAX];

void permutation(int depth, int next)
{
	if (depth == M)
	{
		for(int i = 0; i < M; i++) cout << print[i] << " ";
		cout << endl;
		return;
	}
	int prev = 0;
	for(int i = next; i < N; i++)
	{
		if (visited[i]) continue;
		if (input[i] == prev) continue;
		visited[i] = true;
		prev = input[i];
		print[depth] = input[i];
		permutation(depth + 1, i + 1);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> input[i];
	sort(input, input + N);
	permutation(0, 0);

	return 0;
}
