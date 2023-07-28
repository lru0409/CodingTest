#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int nums[100000];
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	int result = 0;
	int idp[100000];
	int ddp[100000];
	for(int i = 0; i < n; i++)
	{
		idp[i] = 1;
		ddp[i] = 1;
		if (i == 0)
			continue;
		if (nums[i] >= nums[i-1])
			idp[i] = idp[i-1] + 1;
		if (nums[i] <= nums[i-1])
			ddp[i] = ddp[i-1] + 1;
		result = max(result, max(idp[i], ddp[i]));
	}

	if (n == 1)
		cout << "1";
	else
		cout << result;

	return (0);
}
