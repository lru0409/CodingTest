#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if (s1.size() == s2.size())
		return (s1 < s2);
	return (s1.size() < s2.size());
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> words;
	for(int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (find(words.begin(), words.end(), input) == words.end())
			words.push_back(input);
	}

	sort(words.begin(), words.end(), compare);

	for(int i = 0; i < words.size(); i++)
		cout << words[i] << "\n";

	return (0);
}