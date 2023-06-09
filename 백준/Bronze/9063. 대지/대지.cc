#include <iostream>

using namespace std;

int main (void)
{
	int n; // 점의 개수
	cin >> n;

	// 입력 받기
	int x[n], y[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	// x, y 각각에서 가장 큰 것과 작은 것 구하기
	int x_min = x[0], x_max = x[0], y_min = y[0], y_max = y[0];
	for(int i = 1; i < n; i++)
	{
		if (x_min > x[i])
			x_min = x[i];
		else if (x_max < x[i])
			x_max = x[i];
		if (y_min > y[i])
			y_min = y[i];
		else if (y_max < y[i])
			y_max = y[i];
	}
	cout << (x_max - x_min) * (y_max - y_min) << endl; // 가로 길이 * 세로 길이

	return (0);
}