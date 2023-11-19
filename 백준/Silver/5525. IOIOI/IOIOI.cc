#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int N, M;
	string S;
	cin >> N >> M >> S;

	string P;
	for(int i = 0; i < 2 * N + 1; i++)
	{
		if (i % 2 == 0) P += 'I';
		else P += 'O';
	}

	int count = 0;
	for(int i = 0; i < M; i++)
	{
		int s_i = i, p_i = 0;
		while (p_i < P.length() && s_i < S.length() && S[s_i] == P[p_i])
		{
			p_i++;
			s_i++;
		}
		if (p_i == P.length())
			count++;
	}
	cout << count << endl;

	return (0);
}