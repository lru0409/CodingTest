#include <string>
#include <vector>

using namespace std;

// 초침 : 1초에 6도
// 분침 : 1분에 6도, 1초에 0.1도
// 시침 : 1시간에 30도, 1분에 0.5도, 1초에 0.5/60도

int solution(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int ch = h1;
    int cm = m1;
    int cs = s1;
    
    int answer = 0;
    while (ch != h2 || cm != m2 || cs != s2)
    {
        float cs_angle = cs * 6;
        float ns_angle = (cs + 1) * 6;
        
        float cm_angle = (cm * 6) + (cs * 0.1);
        float nm_angle = (cm * 6) + ((cs + 1) * 0.1);
        
        float ch_angle = ((ch % 12) * 30) + (cm * 0.5) + (cs * 1/120.0);
        float nh_angle = ((ch % 12) * 30) + (cm * 0.5) + ((cs + 1) * 1/120.0);
        
        bool overlap_h = false;
        bool overlap_m = false;
        
        if (cs_angle <= ch_angle && nh_angle < ns_angle)
            overlap_h = true;
        if (cs_angle <= cm_angle && nm_angle < ns_angle)
            overlap_m = true;
        if (overlap_h && overlap_m)
        {
            if (ch_angle == cm_angle) answer += 1;
            else answer += 2;
        }
        else if (overlap_h || overlap_m)
            answer += 1;
        
        cs = (cs + 1) % 60;
        if (cs == 0) {
            cm = (cm + 1) % 60;
            if (cm == 0)
                ch += 1;
        }
    }
	if (m2 == 0 && s2 == 0)
		answer += 1;
    
    return answer;
}