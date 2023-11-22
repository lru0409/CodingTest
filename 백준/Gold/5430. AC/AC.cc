#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print_deque(deque<int> dq, bool reverse)
{
	cout << '[';
	if (reverse)
	{
		deque<int>::reverse_iterator iter;
		for(iter = dq.rbegin(); iter != dq.rend(); iter++)
		{
			cout << *iter;
			if (iter + 1 != dq.rend()) cout << ',';
		}
	}
	else
	{
		deque<int>::iterator iter;
		for(iter = dq.begin(); iter != dq.end(); iter++)
		{
			cout << *iter;
			if (iter + 1 != dq.end()) cout << ',';
		}
	}
	cout << "]\n";
}

int main()
{
	int T;
	cin >> T;

	string p, arr;
	int n, tmp, j;
	for(int i = 0; i < T; i++)
	{
		cin >> p >> n >> arr;

		deque<int> x;
		for(j = 1; j < arr.length() - 1; j++)
		{
			int num = 0;
			while ('0' <= arr[j] && arr[j] <= '9')
				num = num * 10 + arr[j++] - '0';
			x.push_back(num);
		}

		bool reverse = false;
		for(j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R')
				reverse = !reverse;
			else if (x.empty())
				break;
			else if (reverse)
				x.pop_back();
			else
				x.pop_front();
		}

		if (j != p.length())
			cout << "error\n";
		else
			print_deque(x, reverse);
	}

	return (0);
}
