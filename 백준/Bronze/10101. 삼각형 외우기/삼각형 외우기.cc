#include <iostream>

using namespace std;

int main (void)
{
	int angle1, angle2, angle3;
	cin >> angle1 >> angle2 >> angle3;

	if (angle1 + angle2 + angle3 != 180)
	{
		cout << "Error" << endl;
		return (0);
	}
	if (angle1 == 60 && angle2 == 60)
	{
		cout << "Equilateral" << endl;
		return (0);
	}
	if (angle1 == angle2 || angle1 == angle3 || angle2 == angle3)
	{
		cout << "Isosceles" << endl;
		return (0);
	}
	cout << "Scalene" << endl;
	
	return (0);
}