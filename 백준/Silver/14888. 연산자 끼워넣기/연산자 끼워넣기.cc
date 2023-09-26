#include <iostream>
#include <vector>
using namespace std;
#define ADDITION 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3

int N, A[11];
vector<int> operators;
int combination[10];
bool visited[10] = { false, };
int minResult = 1000000000;
int maxResult = -1000000000;

int calculate()
{
	int result = A[0];
	for(int i = 1; i < N; i++)
	{
		if (combination[i-1] == ADDITION) {
			result += A[i];
		} else if (combination[i-1] == SUBTRACTION) {
			result -= A[i];
		} else if (combination[i-1] == MULTIPLICATION) {
			result *= A[i];
		} else {
			result /= A[i];
		}
	}
	return (result);
}

void DFS(int depth)
{
	if (depth == N-1)
	{
		int result = calculate();
		if (result < minResult) minResult = result;
		if (result > maxResult) maxResult = result;
		return;
	}
	int prev = -1;
	for(int i = 0; i < N-1; i++)
	{
		if (visited[i]) continue;
		if (operators[i] == prev) continue;
		visited[i] = true;
		prev = operators[i];
		combination[depth] = operators[i];
		DFS(depth + 1);
		visited[i] = false;
	}
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < 4; i++)
	{
		int count;
		cin >> count;
		for(int j = 0; j < count; j++) operators.push_back(i);
	}
	DFS(0);

	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}