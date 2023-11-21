#include <iostream>
#include <cstdlib>
using namespace std;

int N, M;
int broken_buttons[10];

int get_num_len(int number)
{
	if (number == 0)
		return (1);

	int len = 0;
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}

bool is_possible(int number)
{
	if (number == 0)
	{
		for(int i = 0; i < M; i++)
			if (number == broken_buttons[i]) return (false);
		return (true);
	}

	while (number)
	{
		for(int i = 0; i < M; i++)
		{
			if (number % 10 == broken_buttons[i])
				return (false);
		}
		number /= 10;
	}
	return (true);
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
		cin >> broken_buttons[i];
	
	// 100과의 차이
	int diff_from_100 = abs(N - 100);

	// N보다 작은 가능한 가장 가까운 숫자와의 차이
	int small_possible = N;
	bool small_success = true;
	while (small_possible >= 0)
	{
		if (is_possible(small_possible))
			break;
		small_possible--;
	}
	if (small_possible < 0)
		small_success = false;
	int diff_from_small = abs(N - small_possible) + get_num_len(small_possible);

	// N보다 큰 가능한 가장 가까운 숫자와의 차이
	int big_possible = N + 1;
	int diff_form_big = abs(N - big_possible) + get_num_len(big_possible);
	while (true)
	{
		if (diff_form_big >= diff_from_100 || (small_success && diff_form_big >= diff_from_small))
			break;
		if (is_possible(big_possible)) {
			cout << diff_form_big << endl;
			return (0);
		}
		big_possible++;
		diff_form_big = abs(N - big_possible) + get_num_len(big_possible);
	}

	if (small_success && diff_from_small < diff_from_100) {
		cout << diff_from_small << endl;
	} else {
		cout << diff_from_100 << endl;
	}

	return (0);
}