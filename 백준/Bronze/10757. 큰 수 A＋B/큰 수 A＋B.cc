#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
	string s1, s2, tmp;
	int n1[10000], n2[10000];

	// 문자열로 입력 받아 더 긴 것을 s1에 저장
	cin >> s1 >> s2;
	if (s1.length() < s2.length())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// 문자열 s1, s2를 숫자 배열 n1, n2에 저장
	for(int i = 0; i < s1.length(); i++)
		n1[i] = s1[i] - '0';
	for(int i = 0; i < s2.length(); i++)
		n2[s1.length() - s2.length() + i] = s2[i] - '0';
	
	// n1, n2 를 뒤에서부터 한 자리씩 더해서 result 벡터에 저장
	int	sum;
	vector<int> result;
	for(int i = s1.length() - 1; i >= 0; i--)
	{
		sum = n1[i] + n2[i];
		if (sum >= 10 && i == 0)
		{
			result.push_back((n1[0] + n2[0]) % 10);
			result.push_back((n1[0] + n2[0]) / 10);
			break;
		} 
		else if (sum >= 10)
		{
			n1[i - 1] += 1;
			sum -= 10;
		}
		result.push_back(sum);
	}

	// result 벡터 거꾸로 출력
	for(int i = result.size() - 1; i >= 0; i--)
		cout << result[i];

	return (0);
}