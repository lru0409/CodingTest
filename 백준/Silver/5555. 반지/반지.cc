#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;

	int count = 0;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string ring;
		cin >> ring;
		ring.append(ring);
		
		if (ring.find(str) != string::npos)
			count++;
	}
	cout << count << endl;

	return (0);
}
