#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16];
int P[16];

int maxPrice(int day)
{
	if (day > N + 1) return (-15000); // 이 경우 전 상담을 진행할 수 없으므로 해당 경우의 수를 폐기
	if (day == N + 1) return (0); // 이 경우 전 상담을 진행할 수 있음
	if (day == N) { // 이 경우 T[day]가 1이면 상담 진행 가능, 그렇지 않으면 불가능
		if (T[day] == 1) return (P[day]);
		else return (0);
	}

	int price1 = maxPrice(day + T[day]) + P[day]; // day에 상담을 한 경우 얻을 수 있는 최대 수익
	if (T[day] == 1) return (price1); // T[day]가 1이면 이미 [day + 1]의 수익까지 합쳐서 계산됨
	int price2 = maxPrice(day + 1); // day에 상담을 하지 않은 경우 얻을 수 있는 최대 수익

	return (max(price1, price2));
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	cout << maxPrice(1) << endl;

	return (0);
}