#include <iostream>
#include <queue>
using namespace std;

class Queue
{
	private:
		int arr[10001];
		int frontIdx;
		int backIdx;
		int count;
	public:
		Queue() : frontIdx(-1), backIdx(-1), count(0) {}

		void push(int x) {
			count += 1;
			backIdx += 1;
			if (frontIdx == -1) frontIdx = backIdx;
			arr[backIdx] = x;
		}
		int pop() {
			if (empty()) return (-1);
			count -= 1;
			return (arr[frontIdx++]);
		}
		int size() {
			return (count);
		}
		bool empty() {
			if (count == 0) return (true);
			return (false);
		}
		int front() {
			if (empty()) return (-1);
			return (arr[frontIdx]);
		}
		int back() {
			if (empty()) return (-1);
			return (arr[backIdx]);
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Queue Q;
	string input;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		if (input == "push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		else if (input == "pop") {
			cout << Q.pop() << '\n';
		}
		else if (input == "size") {
			cout << Q.size() << '\n';
		}
		else if (input == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (input == "front") {
			cout << Q.front() << '\n';
		}
		else if (input == "back") {
			cout << Q.back() << '\n';
		}
	}

	return 0;
}