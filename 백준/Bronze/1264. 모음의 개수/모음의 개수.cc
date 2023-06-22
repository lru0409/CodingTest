#include <iostream>
using namespace std;

char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

bool checkVowel(char c)
{
	for(int i = 0; i < 10; i++)
	{
		if (c == vowel[i])
			return (true);
	}
	return (false);
}

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int count;
	while (1)
	{
		getline(cin, str);
		if (str == "#")
			break ;
		
		count = 0;
		for(int i = 0; i < str.length(); i++)
		{
			if (checkVowel(str[i]) == true)
				count++;
		}
		cout << count << endl;
	}
	
	return (0);
}