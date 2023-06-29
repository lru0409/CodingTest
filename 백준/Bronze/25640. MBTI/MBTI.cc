#include <iostream>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	string mbti, input;
	int n;
	cin >> mbti >> n;

	int count = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		if (mbti == input)
			count++;
	}
	cout << count;

	return (0);
}
