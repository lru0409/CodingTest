#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
	int m, n;
	cin >> m >> n;

	vector<int> v; // 소수를 저장할 벡터
	for(int i = m; i <= n; i++)
	{
		int count = 0;
		for(int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				count++;
		}
		if (count == 2)
			v.push_back(i);
	}

	int	sum = 0;
	for(int i = 0; i < v.size(); i++)
		sum += v[i];

	if (v.size() > 0)
		cout << sum << endl << v[0] << endl;
	else
		cout << "-1" << endl;

	return (0);
}