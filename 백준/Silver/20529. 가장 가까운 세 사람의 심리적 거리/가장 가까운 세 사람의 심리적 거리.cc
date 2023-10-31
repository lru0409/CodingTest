#include <iostream>
#include <vector>
using namespace std;

int get_distance(string first, string second)
{
	int distance = 0;
	for(int i = 0; i < 4; i++)
	{
		if (first[i] != second[i])
			distance += 1;
	}
	return (distance);
}

int get_min_distance(vector<string> mbti)
{
	int min_distance = 100;
	for(int i = 0; i < mbti.size() - 2; i++)
	{
		for(int j = i + 1; j < mbti.size() - 1; j++)
		{
			for(int k = j + 1; k < mbti.size(); k++)
			{
				int distance = 0;
				distance += get_distance(mbti[i], mbti[j]);
				distance += get_distance(mbti[i], mbti[k]);
				distance += get_distance(mbti[j], mbti[k]);
				if (distance < min_distance) min_distance = distance;
			}
		}
	}
	return (min_distance);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> N;

		vector<string> mbti;
		for(int i = 0; i < N; i++)
		{
			string input;
			cin >> input;
			mbti.push_back(input);
		}
		if (N > 32)
		{
			cout << "0\n";
			continue;
		}
		cout << get_min_distance(mbti) << '\n';
	}
}