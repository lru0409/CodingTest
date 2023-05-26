#include <iostream>

using namespace std;

int main (void)
{
	int count;
	cin >> count;

	int result = 0; // 그룹 단어의 개수
	for(int i = 0; i < count; i++)
	{
		string word;
		cin >> word;

		int alpha[26] = { 0, }; // 등장한 알파벳은 1로 수정
		for(int j = 0; j < word.length(); j++)
		{
			// 앞에(바로 앞은 제외) 같은 알파벳이 등장했다면 반복문 종료
			if (alpha[word[j] - 97] == 1 && word[j - 1] != word[j])
				break;
			alpha[word[j] - 97] = 1;
			// 반복문이 종료되지 않고 끝까지 돌았다면 그룹 단어가 맞음
			if (j == word.length() - 1)
				result++;
		}
	}
	cout << result << endl;

	return (0);
}
