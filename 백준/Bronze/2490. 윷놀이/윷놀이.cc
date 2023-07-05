#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int temp, count;
	for(int i = 0; i < 3; i++)
	{
		count = 0;

		for(int j = 0; j < 4; j++)
		{
			cin >> temp;
			if (temp == 0)
				count++;
		}
		
		if (count == 0) cout << "E" << "\n";
		else if (count == 4) cout << "D" << "\n";
		else if (count == 3) cout << "C" << "\n";
		else if (count == 2) cout << "B" << "\n";
		else if (count == 1) cout << "A" << "\n";
	}

	return (0);
}
