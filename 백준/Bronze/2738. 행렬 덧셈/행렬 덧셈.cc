#include <iostream>

using namespace std;

int main (void)
{
	int n, m; // 행렬의 크기
	cin >> n >> m;

	int **matrixA = new int*[n]; // 행렬 A 동적 할당
	for(int i = 0; i < n; i++)
		matrixA[i] = new int[m];
	int **matrixB = new int*[n]; // 행렬 B 동적 할당
	for(int i = 0; i < n; i++)
		matrixB[i] = new int[m];
	
	for(int i = 0; i < n; i++) // 행렬 A 입력 받기
		for(int j = 0; j < m; j++)
			cin >> matrixA[i][j];
	for(int i = 0; i < n; i++) // 행렬 B 입력 받기
		for(int j = 0; j < m; j++)
			cin >> matrixB[i][j];
		
	for(int i = 0; i < n; i++) // 행렬의 합 출력하기
	{
		for(int j = 0; j < m; j++)
			cout << matrixA[i][j] + matrixB[i][j] << " ";
		cout << endl;
	}

	return (0);
}
