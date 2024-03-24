#include <string>
#include <unordered_set>

using namespace std;

// #include <iostream>
int solution(int N, int number)
{
    unordered_set<int> dp[9]; // i개의 N을 가지고 만들 수 있는 숫자들
    
    // dp 배열의 각 set에 N이 i번 연속된 숫자 추가
    int repeat_num = 0;
    for(int count = 1; count <= 8; count++)
    {
        repeat_num = 10 * repeat_num + N;
        dp[count].insert(repeat_num);
    }
    
    for(int count = 1; count <= 8; count++)
    {
        for(int i = 1; i < count; i++)
        {
            unordered_set<int>::iterator first_it;
            for(first_it = dp[i].begin(); first_it != dp[i].end(); first_it++)
            {
                unordered_set<int>::iterator second_it;
                for(second_it = dp[count-i].begin(); second_it != dp[count-i].end(); second_it++)
                {
                    dp[count].insert(*first_it + *second_it);
                    dp[count].insert(*first_it - *second_it);
                    dp[count].insert(*first_it * *second_it);
                    if (*second_it != 0)
                        dp[count].insert(*first_it / *second_it);
                }
            }
        }
        // cout << "----- count: " << count << " ------\n";
        // unordered_set<int>::iterator it;
        // for(it = dp[count].begin(); it != dp[count].end(); it++)
        //     cout << *it << ' ';
        // cout << '\n';
        if (dp[count].find(number) != dp[count].end())
            return count;
    }
    return -1;
}