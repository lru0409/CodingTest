#include <string>
#include <vector>
using namespace std;

int answer = 0;
vector<int> perm;

void check(vector<int>& numbers, int target)
{
    int result = 0;
    for(int i = 0; i < numbers.size(); i++)
        result += numbers[i] * perm[i];
    if (result == target)
        answer += 1;
}

void permutation(vector<int>& numbers, int target)
{
    if (perm.size() == numbers.size())
    {
        check(numbers, target);
        return;
    }
    perm.push_back(1);
    permutation(numbers, target);
    perm.pop_back();
    perm.push_back(-1);
    permutation(numbers, target);
    perm.pop_back();
}

using namespace std;

int solution(vector<int> numbers, int target)
{
    permutation(numbers, target);
    return answer;
}