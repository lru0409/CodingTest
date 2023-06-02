#include <iostream>

using namespace std;

int	main(void)
{
	int A, B, V; // A미터 오르고, B미터 미끄러질 때, V미터를 며칠 만에 올라가는가
	int result;

	cin >> A >> B >> V;

	// V - A 이상까지 가는 데 걸리는 일수 구하기
	if ((V - A)%(A - B) == 0)
		result = (V - A)/(A - B);
	else
		result = (V - A)/(A - B) + 1;

	// V - A 이상 올라갔다면 그 다음 날 V에 도달하므로 + 1
	cout << result + 1 << endl; // 13 10 4
	return (0);
}