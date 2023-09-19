#include <iostream>
#define MAX 7
using namespace std;

int N, M;
int arr[MAX];

void printArr()
{
	for(int i = 0; i < M; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void permutation(int depth)
{
	if (depth == M)
	{
		printArr();
		return;
	}
	for(int i = 1; i <= N; i++)
	{
		arr[depth] = i;
		permutation(depth + 1);
	}
}

int main(void)
{
	cin >> N >> M;
	permutation(0);

	return (0);
}
