#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;

	vector<int> numbers;
	for(int i = 0; i < n.size(); i++)
		numbers.push_back(n[i] - '0');
	
	sort(numbers.begin(), numbers.end());
	reverse(numbers.begin(), numbers.end());

	for(int i = 0; i < numbers.size(); i++)
		cout << numbers[i];

	return (0);
}