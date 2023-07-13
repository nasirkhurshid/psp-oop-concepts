#include <iostream>
#include "Resistor.h"
using namespace std;

int main()
{
	Resistor x;
	cout << "Resistance: " << x.getR() << endl;
	x.display();
	Resistor r(10);
	r.display();
	r.setR(19);
	cout << "Resistance: " << r.getR() << endl;
	cout << "Current: " << r.getCurrent(15) << endl;
	cout << "Voltage: " << r.getVoltage(13) << endl;
	cout << "Power: " << r[35] << endl;
	cout << "Power: " << r(350) << endl;
	system("PAUSE");
	return 0;
}