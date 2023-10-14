#include <iostream>
using namespace std;

class Stack
{
private:
	int arr[10000];
	int nextIdx;
public:
	Stack() : nextIdx(0) {}
	void push(int x) {
		arr[nextIdx] = x;
		nextIdx += 1;
	}
	int pop() {
		if (empty()) return (-1);
		nextIdx -= 1;
		return (arr[nextIdx]);
	}
	int size() {
		return (nextIdx);
	}
	bool empty() {
		if (nextIdx == 0) return (true);
		return (false);
	}
	int top() {
		if (empty()) return (-1);
		return (arr[nextIdx - 1]);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Stack S;
	for(int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		if (input == "push") {
			int num;
			cin >> num;
			S.push(num);
		}
		else if (input == "pop") {
			cout << S.pop() << '\n';
		}
		else if (input == "size") {
			cout << S.size() << '\n';
		}
		else if (input == "empty") {
			cout << S.empty() << '\n';
		}
		else if (input == "top") {
			cout << S.top() << '\n';
		}
	}

	return 0;
}