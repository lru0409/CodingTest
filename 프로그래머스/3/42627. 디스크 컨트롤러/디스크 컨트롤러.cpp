#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    // pair<소요시간,시작시간>을 담을 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    int answer = 0, time = 0, job_idx = 0; // 정답, 시간, jobs 벡터의 인덱스를 저장할 변수들 초기화

    sort(jobs.begin(), jobs.end()); // jobs 벡터를 시작 시간에 따라 정렬
    while(!PQ.empty() || job_idx < jobs.size()) // 들어올 작업이 남은 경우 반복
    {
        // 현재 시작 가능한 작업을 반복하며 모두 우선순위 큐에 추가
        if(job_idx < jobs.size() && jobs[job_idx][0] <= time)
        {
            PQ.push(make_pair(jobs[job_idx][1], jobs[job_idx][0]));
            job_idx += 1;
            continue;
        }
        
        // 현재 시작 가능한 작업이 없을 경우, time을 다음 작업 시작 시간으로 갱신
        if(PQ.empty())
        {
            time = jobs[job_idx][0];
            continue;
        }
        
        // 현재 시작 가능한 작업 중 가장 소요 시간이 짧은 작업을 수행
        // 우선순위 큐를 소요 시간에 따라 정렬하기 때문에 가능함
        int duration = PQ.top().first;
        int start = PQ.top().second;
        PQ.pop();
        time += duration;
        answer += time - start;
    }
    
	return answer / jobs.size();
}