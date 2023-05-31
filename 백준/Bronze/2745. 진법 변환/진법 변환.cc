#include <iostream>

using namespace std;

int main (void)
{
	string n;
	int b;
	cin >> n >> b;

	int result = 0;
	int num1;
	int num2 = 1;
	for(int i = n.length() - 1; i >= 0; i--)
	{
		if ((int)'A' <= (int)n[i]) // 알파벳이라면
			num1 = (int)n[i] - 'A' + 10;
		else // 숫자라면
			num1 = (int)n[i] - '0';
		result += num1 * num2;
		num2 *= b;
	}
	cout << result << endl;

	return (0);
}
