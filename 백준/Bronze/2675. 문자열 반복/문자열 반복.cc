#include <iostream>

using namespace std;

int main (void)
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		string s;
		int r; // 반복 횟수
		cin >> r >> s;
		
		for(int j = 0; j < s.length(); j++)
		{
			for(int k = 0; k < r; k++)
				cout << s[j];
		}
		cout << endl;
	}

	return (0);
}
