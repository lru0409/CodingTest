#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int time = 0;
	int total_weight = 0;
	int index = 0; // 다음으로 다리에 올라갈 트럭 인덱스
	queue<pair<int, int> > trucks; // 다리를 건너는 트럭 무게, 건너기 시작한 시간

	while(true)
	{
		time += 1;
		// trucks의 첫 트럭이 내려감
		if (!trucks.empty() &&
            trucks.front().second == time - bridge_length)
		{
			total_weight -= trucks.front().first;
			trucks.pop();
			if (trucks.empty() && index == truck_weights.size())
				break; // 모든 트럭이 다리를 건넌 경우 종료
		}

		// index번 트럭이 올라감
		if (index < truck_weights.size() &&
			total_weight + truck_weights[index] <= weight)
		{
			total_weight += truck_weights[index];
			trucks.push(make_pair(truck_weights[index], time));
            index += 1;
		}
	}
	
	return time;
}