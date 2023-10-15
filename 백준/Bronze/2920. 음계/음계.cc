#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int input, prev;

	cin >> prev;
	for(int i = 1; i < 8; i++)
	{
		cin >> input;
		if (prev < input) count += 1;
		else count -= 1;
		prev = input;
	}
	if (count == 7) cout << "ascending" << endl;
	else if (count == -7) cout << "descending" << endl;
	else cout << "mixed" << endl;

	return 0;
}