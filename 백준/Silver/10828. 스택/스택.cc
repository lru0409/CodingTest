#include <iostream>
using namespace std;

class Stack
{
private:
	int arr[10000];
	int topIdx;
public:
	Stack() : topIdx(-1) {}
	void push(int x) {
		topIdx += 1;
		arr[topIdx] = x;
	}
	int pop() {
		if (empty()) return (-1);
		return (arr[topIdx--]);
	}
	int size() {
		return (topIdx + 1);
	}
	bool empty() {
		return (topIdx == -1);
	}
	int top() {
		if (empty()) return (-1);
		return (arr[topIdx]);
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