#include <stdio.h>

int main(void)
{
    int n; // 과목의 개수

    scanf("%d", &n);

    double scores[n]; // 점수들을 저장하는 배열
    int max = 0; // 최대 점수

    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &scores[i]);
        if (scores[i] > max) 
            max = scores[i];
    }

    for(int i = 0; i < n; i++)
        scores[i] = scores[i]/max * 100;
    
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += scores[i];

    printf("%lf", sum /= n);

	return (0);
}