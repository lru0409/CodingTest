#include <iostream>
using namespace std;

int main(void)
{
	int R, B;
	cin >> R >> B;

	int size = R * B;

	int bHeight = 1;
	while (1)
	{
		if (B % bHeight == 0)
		{
			int bWidth = B / bHeight;
			if (R == (bHeight * 2) + (bWidth * 2) + 4)
			{
				cout << bWidth + 2 << " " << bHeight + 2 << endl;
				break;
			}
		}
		bHeight++;
	}

	return (0);
}
