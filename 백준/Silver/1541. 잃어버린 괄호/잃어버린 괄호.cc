#include <iostream>
using namespace std;

int main()
{
	string expression;
	cin >> expression;

	int result = 0;
	bool is_minus = false;
	char prev_sign = '+';
	for(int i = 0; i < expression.length(); i++)
	{
		int num = 0;
		while ('0' <= expression[i] && expression[i] <= '9')
			num = num * 10 + (expression[i++] - '0');
		
		if (is_minus || prev_sign == '-')
			result -= num;
		else
			result += num;

		if (expression[i] == '-')
			is_minus = true;
		prev_sign = expression[i];
	}
	cout << result << endl;
	return (0);
}