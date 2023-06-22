#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> players;

int get_level(string name)
{
	for (auto player = players.begin(); player != players.end(); player++)
	{
		if (player->first == name)
			return (player->second);
	}
	return (0);
}

bool nice_level(string p1, string p2)
{
	int level1 = get_level(p1);
	int level2 = get_level(p2);
	if (level1 - 10 <= level2 && level2 <= level1 + 10)
		return (true);
	return (false);
}

int main(void)
{
	int p, m; // 플레이어 수, 방의 정원
	cin >> p >> m;

	int l;
	string n;
	vector<string> names;
	for (int i = 0; i < p; i++)
	{
		cin >> l >> n;
		players.insert(pair<string, int>(n, l));
		names.push_back(n);
	}

	vector < vector <string> > playersInRoom;
	for (int i = 0; i < names.size(); i++)
	{
		// 생성된 방이 하나도 없는 경우 거르기
		if (playersInRoom.size() == 0)
		{
			vector<string> room;
			room.push_back(names[i]);
			playersInRoom.push_back(room);
			continue ;
		}
		// 들어갈 수 있는 방이 없는 경우(모든 방 정원 참, 레벨 안 맞음) 거르기
		int roomIndex = -1;
		for (int j = 0; j < playersInRoom.size(); j++)
		{
			if (playersInRoom[j].size() == m)
				continue ;
			if (nice_level(playersInRoom[j][0], names[i]) == false)
				continue ;
			roomIndex = j;
			break ;
		}
		if (roomIndex == -1)
		{
			vector<string> room;
			room.push_back(names[i]);
			playersInRoom.push_back(room);
			continue;
		}
		playersInRoom[roomIndex].push_back(names[i]);
	}

	for(int i = 0; i < playersInRoom.size(); i++)
	{
		if (playersInRoom[i].size() == m)
			cout << "Started!" << endl;
		else
			cout << "Waiting!" << endl;
		
		sort(playersInRoom[i].begin(), playersInRoom[i].end());
		for(int j = 0; j < playersInRoom[i].size(); j++)
		{
			int level = get_level(playersInRoom[i][j]);
			cout << level << " " << playersInRoom[i][j] << endl;
		}
	}

	return (0);
}
