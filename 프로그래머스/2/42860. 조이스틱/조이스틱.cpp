#include <string>
#include <vector>

using namespace std;

#include <iostream>

int GetForwardMoveCnt(int& answer, string& name)
{
    int forward_move_cnt = 0; // 순방향 이동 시 이동 횟수
    
    for(int i = 0; i < name.length(); i++)
    {
        // 각 문자 당 최소 조작 횟수 합산
        int diff = name[i] - 'A';
        if (diff < 13)
            answer += diff;
        else
            answer += 26 - diff;

        if (name[i] != 'A' && i != 0) // A가 아닌 문자 && 첫 문자는 제외
            forward_move_cnt = i;
    }

    return forward_move_cnt;
}

int GetReverseMoveCnt(string& name)
{
    // A 집합들의 (이전, 이후) 위치 구하기
    vector<pair<int, int>> A_sets;
    for(int i = 1; i < name.length(); i++)
    {
        if (name[i] != 'A')
            continue;
        int temp = i - 1;
        while(i < name.length() && name[i] == 'A')
            i++;
        A_sets.push_back(make_pair(temp, i));
    }
    
    // A 집합들 순회하며 최소 이동 횟수 구하기
    int reverse_move_cnt = 40;
    for(int i = 0; i < A_sets.size(); i++)
    {
        // A 집합 이전 이동 횟수 = A 집합 이전의 위치 * 2
        // A 집합 이후 이동 횟수 = name 길이 - A 집합 이후의 위치
        // or
        // A 집합 이후 이동 횟수 = (name 길이 - A 집합 이후의 위치) * 2
        // A 집합 이전 이동 횟수 = A 집합 이전의 위치
        int temp1 = (A_sets[i].first * 2) + (name.length() - A_sets[i].second);
        int temp2 = (name.length() - A_sets[i].second) * 2 + A_sets[i].first;
        reverse_move_cnt = min(reverse_move_cnt, min(temp1, temp2));
    }
    return reverse_move_cnt;
}

int solution(string name)
{
    int answer = 0;

    int forward_move_cnt = GetForwardMoveCnt(answer, name);
    int reverse_move_cnt = GetReverseMoveCnt(name);

    // 순방향과 역방향 이동 횟수 중 더 적은 숫자를 합산
    answer += min(forward_move_cnt, reverse_move_cnt);
    
    return answer;
}