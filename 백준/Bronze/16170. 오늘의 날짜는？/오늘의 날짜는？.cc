#include <iostream>
#include <ctime>
using namespace std;

int main (void)
{
	time_t timer = time(NULL);
	struct tm *tm = localtime(&timer);

	cout << tm->tm_year + 1900 << endl;
	if (tm->tm_mon + 1 < 10)
		cout << "0";
	cout << tm->tm_mon + 1 << endl;
	if (tm->tm_mday < 10)
		cout << "0";
	cout << tm->tm_mday << endl;

	return (0);
}