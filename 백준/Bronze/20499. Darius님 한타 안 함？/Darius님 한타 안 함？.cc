#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	int kda[3] = { 0, };
	int idx = 0;
	for(int i = 0; i < 3; i++)
	{
		while(idx < input.length())
		{
			if (input[idx] == '/')
			{
				idx++;
				break ;
			}
			kda[i] = kda[i] * 10 + input[idx] - '0';
			idx++;
		}
	}

	if (kda[0] + kda[2] < kda[1] || kda[1] == 0)
		cout << "hasu";
	else
		cout << "gosu";

	return (0);
}
