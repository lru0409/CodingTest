#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 8

int N, M;
int input[MAX];
int print[MAX];

void permutation(int depth)
{
	if (depth == M)
	{
		for(int i = 0; i < M; i++) cout << print[i] << " ";
		cout << "\n";
		return;
	}
	int prev = 0;
	for(int i = 0; i < N; i++)
	{
		if (input[i] == prev) continue;
		prev = input[i];
		print[depth] = input[i];
		permutation(depth + 1);
	}
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> input[i];
	sort(input, input + N);
	permutation(0);

	return 0;
}
