#include <iostream>

using namespace std;

int	main(void)
{
	int x; // x번째 분수 구하기
	cin >> x;

	int	part = 1; // 몇 번째 소속인가
	int next_num = 2; // 다음 소속의 첫 번째 숫자
	int num_dif = 2; // 현재, 다음 소속 첫 번째 숫자의 차이
	int order = 0; // 현재 소속에서 몇 번째 순서인가
	for(int i = 1; i <= x; i++)
	{
		if (i == next_num)
		{
			part += 1;
			next_num += num_dif;
			num_dif += 1;
			order = 0;
		}
		order += 1;
	}
	int child, parent;
	if (part % 2 == 1)
	{
		child = part - order + 1;
		parent = order;
	}
	else
	{
		child = order;
		parent = part - order + 1;
	}
	cout << child << "/" << parent << endl;
}