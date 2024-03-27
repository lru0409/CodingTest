#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string S;
	cin >> S;

	char prev = ' ';
	int count_zero = 0;
	int count_one = 0;
	for(int i = 0; i < S.size(); i++)
	{
		if (prev != S[i])
		{
			if (S[i] == '0')
				count_zero += 1;
			else
				count_one += 1;
			prev = S[i];
		}
	}

	cout << min(count_zero, count_one) << '\n';
	return 0;
}