#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int N, M;
	string S;
	cin >> N >> M >> S;

	int count = 0;
	for(int i = 0; i < M; i++)
	{
		if (S[i] == 'I')
		{
			int j = 0;
			while (i+2 < S.length() && S[i+1] == 'O' && S[i+2] == 'I')
			{
				i += 2;
				j += 1;
				if (j == N)
				{
					count++;
					j -= 1;
				}
			}
		}
	}
	cout << count << endl;

	return (0);
}