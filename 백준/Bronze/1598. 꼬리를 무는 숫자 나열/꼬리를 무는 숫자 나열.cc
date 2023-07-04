#include <iostream>
#include <cstdlib>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int a_x_pos = (a - 1) / 4;
	int a_y_pos = (a - 1) % 4;
	int b_x_pos = (b - 1) / 4;
	int b_y_pos = (b - 1) % 4;
	cout << abs(a_x_pos - b_x_pos) + abs(a_y_pos - b_y_pos);
	
	return (0);
}
