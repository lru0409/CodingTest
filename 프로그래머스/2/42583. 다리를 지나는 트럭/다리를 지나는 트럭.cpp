#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0;
    int start_idx = 0; // 다리에 올라간 첫 번째 트럭
    int end_idx = -1;  // 다리에 올라간 마지막 트럭
    int total_weight = 0;
    int count[10000];
    
    while(end_idx < (int)truck_weights.size())
    {
		time += 1;
        if (count[start_idx] == bridge_length) { // start_idx의 트럭이 내려감
            total_weight -= truck_weights[start_idx];
			start_idx += 1;
			if (end_idx + 1 == truck_weights.size() &&
				start_idx > end_idx) // 모든 트럭이 다리를 건넌 경우
				break;           // 종료
        }
        
        // 다리를 건너는 중인 트럭들의 count 1씩 증가
        for(int i = start_idx; i <= end_idx; i++)
            count[i] += 1;

		// end_idx+1의 트럭이 올라갈 수 있음
		if (end_idx + 1 < truck_weights.size() &&
			total_weight + truck_weights[end_idx + 1] <= weight)
		{
			end_idx += 1;
			total_weight += truck_weights[end_idx];
	        count[end_idx] = 1;
		}
    }
    
    return time;
}