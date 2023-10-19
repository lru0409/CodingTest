#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int num[100000];
	for(int i = 0; i < n; i++)
		cin >> num[i];
	
	vector<char> result;
	stack<int> S;
	int push_num = 1;
	for(int i = 0; i < n; i++)
	{
		while (S.empty() || S.top() != num[i])
		{
			if (push_num > n)
			{
				cout << "NO\n";
				return (0);
			}
			result.push_back('+');
			S.push(push_num);
			push_num += 1;
		}
		result.push_back('-');
		S.pop();
	}

	for(int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return (0);
}