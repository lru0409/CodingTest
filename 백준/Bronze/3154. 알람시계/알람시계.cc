#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct s_data
{
	int num[4];
	int pos[4][2];
}	t_data;

void getNum(string h, string m, t_data *data)
{
	data->num[0] = h[0] - '0';
	data->num[1] = h[1] - '0';
	data->num[2] = m[0] - '0';
	data->num[3] = m[1] - '0';
}

void getNumPos(t_data *data)
{
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

int getEffort(int idx1, int idx2, t_data *data)
{
	int num1Y = data->pos[idx1][0];
	int num1X = data->pos[idx1][1];
	int num2Y = data->pos[idx2][0];
	int num2X = data->pos[idx2][1];

	return (abs(num1Y - num2Y) + abs(num1X - num2X));
}

int getTotalEffort(t_data *data)
{
	int totalEffort = 0;
	totalEffort += getEffort(0, 1, data);
	totalEffort += getEffort(1, 2, data);
	totalEffort += getEffort(2, 3, data);
	return (totalEffort);
}

string itos(int num)
{
	string str;

	if (num < 10)
		str = "0" + to_string(num);
	else
		str = to_string(num);
	return (str);
}

int main(void)
{
	string realH, realM;

	getline(cin, realH, ':');
	getline(cin, realM);

	int minEffort = 100;
	string minHM[2];
	t_data data;

	int h = stoi(realH, NULL);
	while (h < 100)
	{
		string hStr = itos(h);
		int m = stoi(realM, NULL);
		while (m < 100)
		{
			string mStr = itos(m);
			getNum(hStr, mStr, &data);
			getNumPos(&data);
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