#include <iostream>
#include <string>
using namespace std;

char A[6] = {'A', 'I', 'Y', 'E', 'O', 'U'};
char B[20] = {'B', 'K', 'X', 'Z', 'N', 'H', 'D', 'C', 'W', 'G', 'P', 'V', 'J', 'Q', 'T', 'S', 'R', 'L', 'M', 'F'};
char a[6] = {'a', 'i', 'y', 'e', 'o', 'u'};
char b[20] = { 'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

char change(char *a, char *b, char c)
{
	for(int i = 0; i < 6; i++)
	{
		if (c == a[i])
		{
			i += 3;
			if (i >= 6)
				return (a[i - 6]);
			return (a[i]);
		}
	}
	for(int i = 0; i < 20; i++)
	{
		if (c == b[i])
		{
			i += 10;
			if (i >= 20)
				return (b[i - 20]);
			return (b[i]);
		}
	}
	return (0);
}

int main()
{
	ios_base::sync_with_stdio(false);

	string str;
	while (getline(cin, str))
	{
		int idx = 0;
		int alpha;
		while (str[idx])
		{
			if ('a' <= str[idx] && str[idx] <= 'z')
				str[idx] = change(a, b, str[idx]);
			else if ('A' <= str[idx] && str[idx] <= 'Z')
				str[idx] = change(A, B, str[idx]);
			idx++;
		}
		cout << str << "\n";
	}
	
	return (0);
}
