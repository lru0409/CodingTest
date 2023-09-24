#include <iostream>
#include <algorithm>
#define MAX 7
using namespace std;

int N, M;
int input[MAX];
int print[MAX];

void printArr()
{
	for(int i = 0; i < M; i++)
		cout << print[i] << " ";
	cout << "\n";
}

void permutation(int depth)
{
	if (depth == M)
	{
		printArr();
		return;
	}
	for(int i = 0; i < N; i++)
	{
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
