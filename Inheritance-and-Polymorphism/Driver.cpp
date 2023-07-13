#include "Header.h"
int main()
{
	const int size = 6;
	employee* emp[size];
	emp[0] = new salaried("Ali",0.1, 10000.0);
	emp[1] = new salaried("Akram", 0.25, 20000.0);
	emp[2] = new hourly("Akbar", 0.2, 10.0, 1000.0);
	emp[3] = new hourly("Adeel", 0.23, 20.0, 2500.0);
	emp[4] = new commissioned("Arif", 0.32, 20000.0, 0.35);
	emp[5] = new commissioned("Asim", 0.21, 15000.0, 0.25);

	cout << "Calling calcSalary() function virtually!\n\n";
	showSalary(emp, size);

	cout << "\nCalling display() function virtually!\n\n";
	print(emp, size);

	cout << "Destroying pointer array and the objects stored in it!\n\n";
	destruct(emp, size);

	system("PAUSE");
	return 0;
}