#include <iostream>
using namespace std;

int countDigit(int num)
{
	int count = 0;
	while(num) {
		num /= 10;
		count += 1;
	}
	return count;
}

int main()
{
	int N;
	cin >> N;

	int count = countDigit(N);

	int num1 = 0, num2 = 0;
	for(int i = 0; i < count; i++)
	{
		if (i < count/2)
			num1 += N % 10;
		else
			num2 += N % 10;
		N /= 10;
	}

	if (num1 == num2)
		cout << "LUCKY\n";
	else
		cout << "READY\n";

	return 0;
}
