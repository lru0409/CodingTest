#include <iostream>

using namespace std;

string croationAlpa[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int compare(int idx, string input)
{
	for(int i = 0; i < 8; i++)
	{
		int j = 0;
		while (j < croationAlpa[i].length())
		{
			if (input[idx + j] != croationAlpa[i][j])
				break;
			j++;
		}
		if (j == croationAlpa[i].length())
			return (croationAlpa[i].length());
	}
	return (0);
}

int main (void)
{
	string input;
	cin >> input;

	int result = 0;
	for(int i = 0; i < input.length(); i++)
	{
		int alpaLen = compare(i, input);
		if (alpaLen != 0)
			i += alpaLen - 1;
		result++;
	}
	cout << result << endl;

	return (0);
}