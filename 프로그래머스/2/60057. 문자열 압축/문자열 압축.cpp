#include <string>
#include <vector>

#include <iostream>

using namespace std;

int getCompressedLen(string& s, int count)
{
    // s를 count개 단위로 나눠 divided 벡터에 저장
    vector<string> divided;
    for(int i = 0; i < s.length(); i += count)
        divided.push_back(s.substr(i, count));
    
    int result = 0; // 압축된 문자열의 길이
    string prev = divided[0]; // 비교를 위한 이전 문자열 저장
    int repeat = 1; // 동일한 단위 문자열의 반복 횟수
    // 이 반복문을 돌 때마다 divided[i-1]까지의 최종 길이가 확정됨
    for(int i = 1; i < divided.size(); i++)
    {
        if (prev == divided[i]) {
            repeat += 1;
        } else {
            result += count;
            if (repeat > 1)
                result += to_string(repeat).length();
            repeat = 1;
        }
        prev = divided[i];
    }
    result += prev.length(); // 마지막 문자열을 위한 별도의 처리
    if (repeat > 1)
        result += to_string(repeat).length();
    
    return result;
}

int solution(string s)
{
    int answer = s.length();

    // 단위를 1부터 s길이의 반까지 테스트해보기
    // 단위가 s길이의 반을 넘어가면 어차피 압축이 불가능함
    for(int i = 1; i <= s.length()/2; i++)
    {
        int len = getCompressedLen(s, i); // i개 단위로 압축시켰을 때의 길이
        if (len < answer) // 압축 문자열의 최소 길이 구하기
            answer = len;
    }
    
    return answer;
}