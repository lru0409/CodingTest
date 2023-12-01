#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int> > house;
vector<pair<int, int> > chickenHouse;
vector<int> selectedChickenHouse;

int result = 5000;

int getCityChickenDistance()
{
	int cityChickenDistance = 0;

	for(size_t i = 0; i < house.size(); i++)
	{
		int hx = house[i].first, hy = house[i].second;
		int chickenDistance = 100;
		for(size_t j = 0; j < selectedChickenHouse.size(); j++)
		{
			int selectedIndex = selectedChickenHouse[j];
			int cx = chickenHouse[selectedIndex].first, cy = chickenHouse[selectedIndex].second;
			int distance = abs(hx - cx) + abs(hy - cy);
			if (distance < chickenDistance)
				chickenDistance = distance;
		}
		cityChickenDistance += chickenDistance;
	}
	return (cityChickenDistance);
}

void combination(int depth, int next)
{
	if (depth == M)
	{
		int cityChickenDistance = getCityChickenDistance();
		if (cityChickenDistance < result)
			result = cityChickenDistance;
		return;
	}

	for(size_t i = next; i < chickenHouse.size(); i++)
	{
		selectedChickenHouse.push_back(i);
		combination(depth + 1, i + 1);
		selectedChickenHouse.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
				house.push_back(make_pair(i, j));
			else if (input == 2)
				chickenHouse.push_back(make_pair(i, j));
		}
	}

	combination(0, 0);
	cout << result << '\n';

	return (0);
}
