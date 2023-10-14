#include <iostream>
using namespace std;

class Deque
{
	private:
		int arr[20001];
		int frontIdx;
		int backIdx;
		int count;
	public:
		Deque() : frontIdx(10000), backIdx(9999), count(0) {}
		void push_front(int x) {
			count += 1;
			frontIdx -= 1;
			arr[frontIdx] = x;
		}
		void push_back(int x) {
			count += 1;
			backIdx += 1;
			arr[backIdx] = x;
		}
		int pop_front() {
			if (empty()) return (-1);
			count -= 1;
			return (arr[frontIdx++]);
		}
		int pop_back() {
			if (empty()) return (-1);
			count -= 1;
			return (arr[backIdx--]);
		}
		int size() {
			return (count);
		}
		bool empty() {
			return (count == 0);
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

	Deque D;
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
			cout << D.pop_front() << '\n';
		}
		else if (input == "pop_back") {
			cout << D.pop_back() << '\n';
		}
		else if (input == "size") {
			cout << D.size() << '\n';
		}
		else if (input == "empty") {
			cout << D.empty() << '\n';
		}
		else if (input == "front") {
			cout << D.front() << '\n';
		}
		else if (input == "back") {
			cout << D.back() << '\n';
		}
	}
}