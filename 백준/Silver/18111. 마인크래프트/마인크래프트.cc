#include <iostream>
#include <climits>
using namespace std;


int main()
{
	int M, N, B;
	cin >> M >> N >> B;

	int min = 256, max = 0;
	int land[500][500];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> land[i][j];
			if (land[i][j] < min) min = land[i][j];
			if (land[i][j] > max) max = land[i][j];
		}
	}

	int min_time = INT_MAX;
	int max_height;
	for(int h = min; h <= max; h++)
	{
		int take_out = 0, remove = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				int block = h - land[i][j];
				if (block < 0) remove -= block;
				else take_out += block;
			}
		}
		if (remove + B >= take_out) {
			int time = remove * 2 + take_out;
			if (time <= min_time) {
				min_time = time;
				max_height = h;
			}
		} else {
			break;
		}
	}
	cout << min_time << ' ' << max_height << endl;

	return (0);
}
