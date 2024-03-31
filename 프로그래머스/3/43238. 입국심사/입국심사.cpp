#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    long long answer = n * times[times.size()-1];
    
    long long left = 1;
    long long right = n * (long long)times[times.size()-1]; // 27 27
    while (left <= right)
    {
        long long mid = (left + right) / 2; // mid분 만에 가능한가?
        long long count = 0; // mid분 동안 심사 가능한 사람 수

        for(int i = 0; i < times.size(); i++)
            count += mid / (long long)times[i];

        if (n <= count) {
            right = mid - 1;
            answer = min(answer, mid);
        } else {
            left = mid + 1;
        }
    }
    return answer;
}
