#include <iostream>
#include "Resistor.h"
using namespace std;

Resistor::Resistor()
{
	res = 0;
}


Resistor::Resistor(double x)
{
	res = x;
}

void Resistor::setR(double x)
{
	cout << "Setter called!\n";
	res = x;
}

double Resistor::getR() const
{
	cout << "Getter called!\n";
	return this->res;
}

double Resistor::getCurrent(double v)
{
	double i;
	i = v / res;
	return i;
}

double Resistor::getVoltage(double i)
{
	double v;
	v = res * i;
	return v;
}

double Resistor::operator [] (double i)
{
	double p;
	p = i*i*this->res;
	return p;
}

double Resistor::operator () (double v)
{
	double p;
	p = (v*v)/this->res ;
	return p;
}

void Resistor::display()
{
	cout << "Resistance: " << res << endl;
}

Resistor::~Resistor()
{
	cout << "Destructor called!\n";
}