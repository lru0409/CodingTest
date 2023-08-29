#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct s_data
{
	int num[4];
	int pos[4][2];
}	t_data;

string itos(int num)
{
	string str;

	if (num < 10)
		str = "0" + to_string(num);
	else
		str = to_string(num);
	return (str);
}

void setData(string h, string m, t_data *data)
{
	data->num[0] = h[0] - '0';
	data->num[1] = h[1] - '0';
	data->num[2] = m[0] - '0';
	data->num[3] = m[1] - '0';

	for(int i = 0; i < 4; i++)
	{
		if (data->num[i] == 0)
		{
			data->pos[i][0] = 3;
			data->pos[i][1] = 1;
			continue;
		}
		data->pos[i][0] = (data->num[i] - 1) / 3;
		data->pos[i][1] = (data->num[i] - 1) % 3;
	}
}

int getTotalEffort(t_data *data)
{
	int totalEffort = 0;
	int num1Y, num1X, num2Y, num2X;

	for(int i = 0; i <= 2; i++)
	{
		num1Y = data->pos[i][0];
		num1X = data->pos[i][1];
		num2Y = data->pos[i + 1][0];
		num2X = data->pos[i + 1][1];
		totalEffort += abs(num1Y - num2Y) + abs(num1X - num2X);
	}
	return (totalEffort);
}

int main(void)
{
	string inputH, inputM;
	getline(cin, inputH, ':');
	getline(cin, inputM);
	int realH = stoi(inputH, NULL);
	int realM = stoi(inputM, NULL);

	int minEffort = 100;
	string minHM[2];
	t_data data;

	int h = realH;
	while (h < 100)
	{
		string hStr = itos(h);
		int m = realM;
		while (m < 100)
		{
			string mStr = itos(m);
			setData(hStr, mStr, &data); // 네 개의 숫자와 각 위치를 저장
			int totalEffort = getTotalEffort(&data);
			if (totalEffort < minEffort)
			{
				minEffort = totalEffort;
				minHM[0] = hStr;
				minHM[1] = mStr;
			}
			m += 60;
		}
		h += 24;
	}

	cout << minHM[0] << ":" << minHM[1] << endl;

	return (0);
}