#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
	int n;

	while (1)
	{
		cin >> n;
		if (n == -1)
			break;

		// 약수를 벡터에 저장
		vector<int> v;
		for(int i = 1; i < n; i++)
			if (n % i == 0)
				v.push_back(i);
		
		// 약수 합 구하기
		int sum = 0;
		for(int i = 0; i < v.size(); i++)
			sum += v[i];
		
		// 완전수인지 아닌지 확인 후 처리
		if (sum == n) {
			cout << n << " = ";
			for(int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i != v.size() - 1)
					cout << " + ";
			}
		} else {
			cout << n << " is NOT perfect.";
		}
		cout << endl;
	}

	return (0);
}