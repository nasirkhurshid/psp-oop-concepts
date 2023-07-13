#include <iostream>
using namespace std;

class Resistor {
	double res;
public:
	Resistor();
	Resistor(double x);
	void setR(double x);
	double getR() const;
	double getCurrent(double v);
	double getVoltage(double i);	
	double operator [] (double i);
	double operator () (double v);
	void display();
	~Resistor();
};