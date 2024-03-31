#include <string>
#include <vector>
#include <queue>

using namespace std;
#include <iostream>
int solution(vector<int> priorities, int location)
{
    priority_queue<int> PQ; // 우선순위, 처음 위치
    queue<pair<int, int> > Q;

    for(int i = 0; i < priorities.size(); i++) {
        PQ.push(priorities[i]);
        Q.push(make_pair(priorities[i], i));
    }
    
    int count = 1;
    while(!PQ.empty()) // 현재 큐에서 우선순위가 가장 높은 프로세스 찾기
    {
        int pr = Q.front().first;
        int pos = Q.front().second;
        Q.pop();
        // 현재 우선순위가 가장 높은 (실행할) 프로세스를 찾은 경우
        if (PQ.top() == pr)
        {
            if (pos == location) // location에 일치하는 프로세스인 경우
                break;
            PQ.pop();
            count += 1;
        }
        else
        {
            Q.push(make_pair(pr, pos));
        }
    }

    return count;
}