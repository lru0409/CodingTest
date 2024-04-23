#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

int N;
int numbers[11] = {0, };
int op_cnt[4] = {0, };

vector<int> ops;
int min_result = 1000000000; 
int max_result = -1000000000;

int Calculate()
{
	int result = numbers[0];
	int op_idx = 0;
	for(int nbr_idx = 1; nbr_idx < N; nbr_idx++)
	{
		switch (ops[op_idx])
		{
			case PLUS: result += numbers[nbr_idx]; break;
			case MINUS: result -= numbers[nbr_idx]; break;
			case MULTIPLY: result *= numbers[nbr_idx]; break;
			case DIVIDE: result /= numbers[nbr_idx]; break;
		}
		op_idx++;
	}
	return result;
}

void DFS()
{
	if (ops.size() == N - 1) {
		int result = Calculate();
		min_result = min(min_result, result);
		max_result = max(max_result, result);
		return;
	}

	for(int i = 0; i < 4; i++) {
		if (op_cnt[i] == 0)
			continue;
		op_cnt[i] -= 1;
		ops.push_back(i);
		DFS();
		ops.pop_back();
		op_cnt[i] += 1;
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> numbers[i];
	for(int i = 0; i < 4; i++)
		cin >> op_cnt[i];
	
	DFS();
	cout << max_result << '\n';
	cout << min_result << '\n';

	return 0;
}