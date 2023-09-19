#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX];
bool check[MAX] = { false, };

void printArr()
{
	for(int i = 0; i < M; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void permutation(int depth)
{
	if (depth == M) {
		printArr();
		return;
	}

	for(int i = 1; i <= N; i++)
	{
		if (check[i] == false) {
			check[i] = true;
			arr[depth] = i;
			permutation(depth + 1);
			check[i] = false;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	permutation(0);
	return (0);
}
