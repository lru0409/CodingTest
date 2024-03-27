#include <string>
#include <vector>
using namespace std;

int answer = 0;

void DFS(int sum, int count, vector<int>& numbers, int target)
{
    if (count == numbers.size())
    {
        if (sum == target)
            answer += 1;
        return;
    }
    DFS(sum + numbers[count], count + 1, numbers, target);
    DFS(sum - numbers[count], count + 1, numbers, target);
}

using namespace std;

int solution(vector<int> numbers, int target)
{
    DFS(0, 0, numbers, target);
    return answer;
}