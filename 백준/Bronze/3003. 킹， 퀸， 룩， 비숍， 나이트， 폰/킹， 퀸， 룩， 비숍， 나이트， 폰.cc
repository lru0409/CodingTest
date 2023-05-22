#include <iostream>

using namespace std;

int main (void)
{
	int totalCount[6] = { 1, 1, 2, 2, 2, 8 }; // 킹, 퀸, 룩, 비숍, 나이트, 폰
	int curCount[6];

	for(int i = 0; i < 6; i++)
		cin >> curCount[i];
		
	for(int i = 0; i < 6; i++)
		cout << totalCount[i] - curCount[i] << " ";

	return (0);
}