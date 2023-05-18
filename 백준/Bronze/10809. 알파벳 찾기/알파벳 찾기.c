#include <stdio.h>

int main(void)
{
	char str[100];
	int alpabets[26]; // 처음 등장하는 위치를 저장하는 배열

	for (int i = 0; i < 26; i++)
		alpabets[i] = -1;

	scanf("%s", str);

	int idx = 0;
	while (str[idx])
	{
		int alpabetIdx = (int)str[idx] - 97;
		if (alpabets[alpabetIdx] == -1)
			alpabets[alpabetIdx] = idx;
		idx++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", alpabets[i]);

	return (0);
}