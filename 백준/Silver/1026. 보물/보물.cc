#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> A;
	vector<int> B;

	int input;
	for(int i = 0; i < n * 2; i++)
	{
		cin >> input;
		if (i < n) A.push_back(input);
		else B.push_back(input);
	}

	int result = 0;
	for(int i = 0; i < n; i++)
	{
		int mini = 0;
		for(int j = 1; j < n-i; j++)
			if (A[j] < A[mini])
				mini = j;

		int maxi = 0;
		for(int j = 1; j < n-i; j++)
			if(B[j] > B[maxi])
				maxi = j;

		result += A[mini] * B[maxi];
		A.erase(A.begin() + mini);
		B.erase(B.begin() + maxi);
	}
	cout << result;
	
	return (0);
}
