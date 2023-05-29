#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int matrix[100][100];
    for(int i = 0; i < 100; i++) // 도화지 초기화
        for(int j = 0; j < 100; j++)
            matrix[i][j] = 0;

    int n; // 색종이 개수
    cin >> n;

    int x, y;
    for(int i = 0; i < n; i++)  // 색종이가 붙은 영역 표시
    {
        cin >> x >> y;
        for(int j = y - 1; j < y + 9; j++)
            for(int k = x - 1; k < x + 9; k++)
                matrix[j][k] = 1;
    }

    int result = 0;
    for(int i = 0; i < 100; i++) // 색종이가 붙은 넓이 구하기
        for(int j = 0; j < 100; j++)
            if (matrix[i][j] == 1)
                result++;

    cout << result << endl;

	return (0);
}