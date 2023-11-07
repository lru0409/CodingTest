#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x;
	cin >> N;

	priority_queue<int, vector<int>, greater<int> > positive;
	priority_queue<int, vector<int>, less<int> > negative;
	while (N--)
	{
		cin >> x;
		if (x == 0) {
			if (positive.empty() && negative.empty()) {
				cout << '0' << '\n';
			} else if (positive.empty()) {
				cout << negative.top() << '\n';
				negative.pop();
			} else if (negative.empty()) {
				cout << positive.top() << '\n';
				positive.pop();
			} else if (abs(positive.top()) < abs(negative.top())) {
				cout << positive.top() << '\n';
				positive.pop();
			} else {
				cout << negative.top() << '\n';
				negative.pop();
			}
		} else if (x >= 0) {
			positive.push(x);
		} else {
			negative.push(x);
		}

	}

	return (0);
}