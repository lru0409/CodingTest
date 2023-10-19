#include <iostream>
#include <stack>
using namespace std;

int main()
{
	while (true)
	{
		string input;
		getline(cin, input);
		if (input == ".")
			break;
		
		stack<char> bracket;
		string result = "yes";
		for(int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(' || input[i] == '[')
				bracket.push(input[i]);
			if (input[i] == ')' || input[i] == ']')
			{
				if ((input[i] == ')' && !bracket.empty() && bracket.top() == '(')
					|| (input[i] == ']' && !bracket.empty() && bracket.top() == '[')) {
					bracket.pop();
				} else {
					result = "no";
					break;
				}
			}
		}
		if (!bracket.empty()) result = "no";
		cout << result << endl;
	}

	return (0);
}