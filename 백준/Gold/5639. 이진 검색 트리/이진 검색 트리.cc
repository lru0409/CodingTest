#include <iostream>
using namespace std;

int tree[10000];

void post_order(int start, int end) // 서브트리의 시작 인덱스, 끝 + 1 인덱스
{
	if (start >= end)
		return;

	int index = start + 1; // 왼쪽 서브트리의 끝 + 1, 오른쪽 서브트리의 시작 인덱스
	while (index < end)
	{
		if (tree[start] < tree[index])
			break;
		index++;
	}
	
	post_order(start + 1, index);
	post_order(index, end);
	cout << tree[start] << '\n';
}

int main()
{
	int index = 0, num;
	while (cin >> num)
		tree[index++] = num;
	
	post_order(0, index);

	return (0);
}
