#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> D;
	string input;
	int num;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		if (input == "push_front") {
			cin >> num;
			D.push_front(num);
		}
		else if (input == "push_back") {
			cin >> num;
			D.push_back(num);
		}
		else if (input == "pop_front") {
			if (D.empty()) {
				cout << -1 << endl;
			} else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (D.empty()) {
				cout << -1 << endl;
			} else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (input == "size") {
			cout << D.size() << '\n';
		}
		else if (input == "empty") {
			cout << D.empty() << '\n';
		}
		else if (input == "front") {
			if (D.empty()) cout << -1 << endl;
			else cout << D.front() << '\n';
		}
		else if (input == "back") {
			if (D.empty()) cout << -1 << endl;
			else cout << D.back() << '\n';
		}
	}
}