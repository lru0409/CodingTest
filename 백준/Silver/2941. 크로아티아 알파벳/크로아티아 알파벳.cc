#include <iostream>

using namespace std;

string croation[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main (void)
{
	string input;
	cin >> input;

	int idx;
	for(int i = 0; i < 8; i++)
	{
		while(1)
		{
			idx = input.find(croation[i]);
			if (idx == string::npos)
				break;
			input.replace(idx, croation[i].length(), "#");
		}
	}
	cout << input.length() << endl;

	return (0);
}