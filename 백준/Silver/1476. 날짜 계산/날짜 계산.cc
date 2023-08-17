#include <iostream>
using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;

	int esm[3] = {1, 1, 1};
	int year = 1;
	while (1)
	{
		if (esm[0] == e && esm[1] == s && esm[2] == m) break;

		esm[0]++;
		esm[1]++;
		esm[2]++;
		year++;

		if (esm[0] > 15)
			esm[0] = 1;
		if (esm[1] > 28)
			esm[1] = 1;
		if (esm[2] > 19)
			esm[2] = 1;
	}
	cout << year << endl;

	return (0);
}