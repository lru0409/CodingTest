#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M;
int input[MAX];
int print[MAX];

void permutation(int depth, int next)
{
	if (depth == M)
	{
		for(int i = 0; i < M; i++) cout << print[i] << " ";
		cout << "\n";
		return;
	}
	int prev = 0;
	for(int i = next; i < N; i++)
	{
		if (prev == input[i]) continue;
		prev = input[i];
		print[depth] = input[i];
		permutation(depth + 1, i);
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