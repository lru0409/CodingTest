#include <iostream>

using namespace std;

int main (void)
{
	int matrix[9][9];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			cin >> matrix[i][j];
	
	int max = -1; // 최댓값
	int position[2]; // 최댓값 좌표
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				position[0] = i;
				position[1] = j;
			}
		}
	}
	cout << max << endl;
	cout << position[0] + 1 << " " << position[1]  + 1 << endl;

	return (0);
}
