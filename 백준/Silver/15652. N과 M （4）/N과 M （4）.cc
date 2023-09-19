#include <iostream>
#define MAX 8
using namespace std;

int N, M;
int arr[MAX];

void printArr()
{
	for(int i = 0; i < M; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void permutation(int depth, int next)
{
	if (depth == M)
	{
		printArr();
		return;
	}
	for(int i = next; i <= N; i++)
	{
		arr[depth] = i;
		permutation(depth + 1, i);
	}
}

int main(void)
{
	cin >> N >> M;
	permutation(0, 1);
	return (0);
}
