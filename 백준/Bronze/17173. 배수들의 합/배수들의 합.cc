#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	int K[1000];
	for(int i = 0; i < M; i++)
		cin >> K[i];
	
	set<int> s;
	for(int i = 0; i < M; i++) {
		int k = K[i];
		for(int j = 1; K[i] * j <= N; j++) {
			s.insert(K[i] * j);
		}
	}

	int sum = 0;
	set<int>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++) {
		sum += *iter;
	}
	cout << sum << endl;

	return (0);
}
