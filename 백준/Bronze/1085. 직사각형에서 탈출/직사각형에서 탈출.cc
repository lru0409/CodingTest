#include <iostream>

using namespace std;

int main (void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min1 = min(x, y);
	int min2 = min(w-x, h-y);

	// x, y, w - x, h - y 중 제일 작은 값 출력
	cout << min(min1, min2) << endl;

	return (0);
}