#include <iostream>

using namespace std;

int main (void)
{
	string n;
	int b;
	cin >> n >> b;

	int result = 0;
	int num1, num2;
	for(int i = 0; i < n.length(); i++)
	{
		if ((int)'A' <= (int)n[i] && (int)n[i] <= (int)'Z') // 알파벳이라면
			num1 = (int)n[i] - 55;
		else // 숫자라면
			num1 = (int)n[i] - 48;

		num2 = 1;
		for(int j = 0; j < n.length() - i - 1; j++)
			num2 *= b;

		result += num1 * num2;
	}
	cout << result << endl;

	return (0);
}
