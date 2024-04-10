#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 재생횟수 리스트 정렬 (재생횟수 내림차순, 고유 번호 오름차순)
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first < p2.first)
        return false;
    if (p1.first > p2.first)
        return true;
    return p1.second < p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    // map에 장르별 재생횟수 리스트 & 총 재생횟수 저장
    map<string, vector<pair<int, int>>> songs; // 장르별 재생 횟수, 고유번호
    map<string, int> genre_plays; // 장르별 총 재생 횟수
    for(int i = 0; i < genres.size(); i++) {
        songs[genres[i]].push_back(make_pair(plays[i], i));
        genre_plays[genres[i]] += plays[i];
    }
    
    // 총 재생 횟수 순으로 장르 나열하기
    vector<pair<int, string> > sorted;
    map<string, int>::iterator it;
    for(it = genre_plays.begin(); it != genre_plays.end(); it++)
        sorted.push_back(make_pair(it->second, it->first));
    sort(sorted.begin(), sorted.end(), greater<pair<int, string>>());
    
    vector<int> answer;
    // 재생 횟수가 많은 장르부터 순서대로 반복
    for(int i = 0; i < sorted.size(); i++)
    {
        string genre = sorted[i].second;
        // 재생횟수 리스트 정렬 (재생횟수 내림차순, 고유 번호 오름차순)
        sort(songs[genre].begin(), songs[genre].end(), comp);
        answer.push_back(songs[genre][0].second); // 첫번째로 많이 재생한 노래 고유 번호 추가
        if (songs[genre].size() > 1)
            answer.push_back(songs[genre][1].second); // 두번째로 많이 재생한 노래 고유 번호 추가
    }

    return answer;
}