#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer;
    
    int answer_size = number.size() - k;
    int start_idx = 0;
    for(int i = 0; i < answer_size; i++)
    {
        // 현재 answer에 추가할 수 있는 범위에서 가장 큰 수 찾기
        int max_idx = start_idx;
        for(int j = start_idx + 1; j <= start_idx + k; j++) {
            if (number[max_idx] < number[j])
                max_idx = j;
        }
        
        answer += number[max_idx];
        k -= max_idx - start_idx;
        start_idx = max_idx + 1;
    }

    return answer;
}
