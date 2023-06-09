#include <iostream>

using namespace std;

int main (void)
{
	int len[3];
	int maxIdx;
	
	while(1)
	{
		cin >> len[0] >> len[1] >> len[2];
		if (len[0] == 0)
			break;
		
		// 가장 큰 값의 인덱스 구하기
		maxIdx = 0;
		for(int i = 1; i < 3; i++)
		{
			if (len[i] > len[maxIdx])
				maxIdx = i;
		}

		// 가장 작은 변들끼리의 합 구하기
		int sum = 0; 
		for(int i = 0; i < 3; i++)
		{
			if (i != maxIdx)
				sum += len[i];
		}

		if (sum <= len[maxIdx])
			cout << "Invalid" << endl;
		else if (len[0] == len[1] && len[1] == len[2])
			cout << "Equilateral" << endl;
		else if (len[0] == len[1] || len[0] == len[2] || len[1] == len[2])
			cout << "Isosceles" << endl;
		else
			cout << "Scalene" << endl;
	}
	return (0);
}