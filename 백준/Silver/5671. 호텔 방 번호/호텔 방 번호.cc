#include <iostream>
using namespace std;

bool noRepeat(int num)
{
	int counting[10] = { 0, };
	while(num)
	{
		counting[num % 10] += 1;
		num /= 10;
	}
	for(int i = 0; i < 10; i++)
		if (counting[i] > 1) return (false);
	return (true);
}

int main(void)
{
	int N, M;

	while (1)
	{
		cin >> N >> M;
		if (cin.eof()) break;

		int count = 0;
		for(int i = N; i <= M; i++)
			if (noRepeat(i)) count++;
		cout << count << endl;
	}

	return (0);
}
