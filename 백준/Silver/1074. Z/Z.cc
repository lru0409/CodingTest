#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void Z(int size, int y, int x)
{
	if (y == r && x == c) {
		cout << result << endl;
		return;
	}

	if (!(y <= r && r < y + size && x <= c && c < x + size)) {
		result += pow(size, 2);
		return;
	}

	Z(size/2, y, x);
	Z(size/2, y, x + size/2);
	Z(size/2, y + size/2, x);
	Z(size/2, y + size/2, x + size/2);
}

int main()
{
	cin >> N >> r >> c;

	Z(pow(2, N), 0, 0);

	return (0);
}