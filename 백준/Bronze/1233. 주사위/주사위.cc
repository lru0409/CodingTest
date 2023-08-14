#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int counts[81] = { 0, };
	for(int i = 1; i <= s1; i++)
	{
		for(int j = 1; j <= s2; j++)
		{
			for(int k = 1; k <= s3; k++)
			{
				counts[i + j + k]++;
			}
		}
	}

	int max = s1 + s2 + s3;
	for(int i = s1 + s2 + s3 - 1; i >= 1; i--)
		if (counts[i] >= counts[max]) max = i;
	
	cout << max << "\n";
	
	return (0);
}