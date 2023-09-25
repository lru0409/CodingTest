#include <iostream>
#include <cmath>
#include <algorithm>
#define X 0
#define Y 1
using namespace std;

int stop[2], train[2], d[2];

int getDivisor(int x, int y)
{
	if (x == 0 || y == 0) return (0);
	int smaller = min(abs(x), abs(y));
	int bigger = max(abs(x), abs(y));

	int i = 1;
	while (1)
	{
		if (smaller % i == 0) {
			int div = smaller / i;
			if (bigger % div == 0) return (div);
		}
		i++;
	}
}

void fixD()
{
	if (d[X] == 0 && d[Y] != 0) {
		d[Y] = 1;
		return;
	}
	if (d[Y] == 0 && d[X] != 0) {
		d[X] = 1;
		return;
	}
	if (d[Y] == 0 && d[X] == 0) return;

	int div = getDivisor(d[Y], d[X]);
	d[Y] /= div;
	d[X] /= div;
}

double getDistance(int x, int y)
{
	double distance = pow((x - stop[X]), 2) + pow((y - stop[Y]), 2);
	return distance;
}

int main(void)
{
	cin >> stop[X] >> stop[Y] >> train[X] >> train[Y] >> d[X] >> d[Y];

	fixD();
	double prev = getDistance(train[X], train[Y]);

	while (1)
	{
		train[X] += d[X];
		train[Y] += d[Y];
		double distance = getDistance(train[X], train[Y]);
		if (prev <= distance) break;
		prev = distance;
	}
	cout << train[X] - d[X] << " " << train[Y] - d[Y] << endl;

	return 0;
}