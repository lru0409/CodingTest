#include <iostream>
using namespace std;

int N;
long long B;
int A[5][5];
int temp[5][5];
int result[5][5];

// a에 b를 곱합
void matrix_multi(int a[5][5], int b[5][5])
{
	for(int r = 0; r < N; r++) { // a의 r번째 행 선택
		for(int c = 0; c < N; c++) { // b의 c번째 열 선택
			temp[r][c] = 0;
			for(int j = 0; j < N; j++) {
				temp[r][c] += a[r][j] * b[j][c];
			}
		}
	}
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			a[r][c] = temp[r][c] % 1000;
		}
	}
}

int main()
{
	cin >> N >> B;
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			cin >> A[r][c];
		}
		result[r][r] = 1;
	}

	while (B > 0)
	{
		if (B % 2 == 1) {
			matrix_multi(result, A);
			if (B == 1) break;
		}
		matrix_multi(A, A);
		B /= 2;
	}

	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			cout << result[r][c] << ' ';
		}
		cout << '\n';
	}
	
	return (0);
}