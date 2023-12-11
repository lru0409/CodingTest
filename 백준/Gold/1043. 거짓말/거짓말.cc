#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 사람 수, 파티 수
queue<int> Q; // 진실을 아는 사람들을 담을 큐
bool truth_person[51]; // 그 사람이 진실을 아는가
vector<vector<int> > partys; // 파티들에 오는 사람들 정보
bool truth_party[51]; // 그 파티에서 진실을 말해야 하는 가
int truth_party_cnt = 0; // 진실을 말해야 하는 파티 수

void getTruthPartCnt()
{
	while (!Q.empty())
	{
		int person = Q.front();
		Q.pop();

		for(size_t i = 0; i < partys.size(); i++)
		{
			// 만약 그 파티에 진실을 아는 사람이 포함되어 있다면
			if (find(partys[i].begin(), partys[i].end(), person) != partys[i].end())
			{
				// 그 파티의 모든 사람을 '진실을 아는 사람'으로 판단
				for(size_t j = 0; j < partys[i].size(); j++)
				{
					int num = partys[i][j];
					if (truth_person[num] == false)
					{
						Q.push(num);
						truth_person[num] = true;
					}
				}
				// 그리고 그 파티를 '진실을 말해야 하는 파티'로 판단
				if (truth_party[i] == false)
				{
					truth_party[i] = true;
					truth_party_cnt += 1;
				}
			}
		}

	}
}

int main()
{
	cin >> N >> M;

	int cnt, num;
	cin >> cnt; // 진실을 아는 사람의 수
	for(int i = 0; i < cnt; i++)
	{
		cin >> num; // 진실을 아는 사람의 번호
		Q.push(num);
		truth_person[num] = true;
	}
	for(int i = 0; i < M; i++)
	{
		vector<int> party;
		cin >> cnt; // 파티에 오는 사람의 수
		for(int i = 0; i < cnt; i++)
		{
			cin >> num; // 파티에 오는 사람의 번호
			party.push_back(num);
		}
		partys.push_back(party);
	}

	getTruthPartCnt(); // truth_person 배열을 통해 진실을 아는 사람 가려내기
	cout << M - truth_party_cnt << '\n';

	return (0);
}
