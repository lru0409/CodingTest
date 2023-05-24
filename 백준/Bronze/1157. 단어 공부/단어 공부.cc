#include <iostream>
#include <cctype>

using namespace std;

int main (void)
{
	int alpabetCounts[26] = { 0, };

	string input;
	cin >> input;

	for(int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
		alpabetCounts[input[i] - 65] += 1;
	}

	int maxCount = 0;
	char maxIndex;
	for(int i = 0; i < 26; i++)
	{
		if (alpabetCounts[i] > maxCount)
		{
			maxCount = alpabetCounts[i];
			maxIndex = i;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if (maxIndex != i && maxCount == alpabetCounts[i])
		{
			cout << "?" << endl;
			return (0);
		}
	}

	cout << (char)(maxIndex + 65) << endl;
	return (0);
}