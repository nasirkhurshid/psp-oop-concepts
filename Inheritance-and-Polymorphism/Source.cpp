#include "Header.h"

////////////////
//STRING CLASS//
////////////////

mystring::mystring() {
	n = NULL;
}

mystring::mystring(const char* n) {
	if (n != NULL) {
		this->n = new char[strlen(n) + 1];
		strcpy(this->n, n);
	}
	else {
		this->n = NULL;
	}
}

mystring::mystring(const mystring& str) {
	if (this->n != NULL) {
		delete[] this->n;
		this->n = NULL;
	}
	if (str.n != NULL) {
		this->n = new char[strlen(str.n) + 1];
		strcpy(this->n, str.n);
	}
}

void mystring::setstring(const char* n) {
	if (this->n != NULL) {
		delete[] this->n;
		this->n = NULL;
	}
	if (n != NULL) {
		this->n = new char[strlen(n) + 1];
		strcpy(this->n, n);
	}
}

char* mystring::getstring() const {
	return this->n;
}

mystring::~mystring() {
	delete[] n;
	cout << "MyString Destructor called1!\n";
}

//////////////////
//EMPLOYEE CLASS//
//////////////////

employee::employee() {
	name.setstring(NULL);
	taxrate = 0.0;
}

employee::employee(const char* n, double r) {
	name.setstring(n);
	taxrate = r;
}

void employee::setname(const char* n) {
	name.setstring(n);
}

char* employee::getname() const {
	return name.getstring();
}

void employee::settaxrate(double taxrate) {
	this->taxrate = taxrate;
}

double employee::gettaxrate() const {
	return this->taxrate;
}

employee::~employee() {
	cout << "Employee Destructor called1!\n";
}

//////////////////
//SALARIED CLASS//
//////////////////

salaried::salaried():employee() {
	salary = 0.0;
}

salaried::salaried(const char* n, double taxrate, double salary) : employee(n, taxrate) {
	this->salary = salary;
}

void salaried::setsalary(double salary) {
	this->salary = salary;
}

double salaried::grossSalary() {
	return this->salary;
}

double salaried::calcSalary() {
	double res = salary - (taxrate * salary);
	return res;
}

void salaried::display() {
	cout << "Displaying Data for Salaried Employee:\n";
	cout << "Name: " << getname() << endl;
	cout << "Gross Salary: " << grossSalary() << endl;
	cout << "Tax Rate: " << gettaxrate() << "\t(" << gettaxrate() * 100 << "%)" << endl;
	cout << "Net Salary: " << calcSalary() << endl;
}

salaried::~salaried(){
	cout << "Salaried Destructor called1!\n";
}

///////////////////
//HOURLY EMPLOYEE//
///////////////////

hourly::hourly():employee() {
	hours = 0.0;
	hourlyrate = 0.0;
}

hourly::hourly(const char* n, double taxrate, double hours, double hourlyrate) : employee(n, taxrate) {
	this->hours = hours;
	this->hourlyrate = hourlyrate;
}

void hourly::sethours(double hours) {
	this->hours = hours;
}

double hourly::gethours() const {
	return this->hours;
}

void hourly::sethourlyrate(double hourlyrate) {
	this->hourlyrate = hourlyrate;
}

double hourly::gethourlyrate() const {
	return this->hourlyrate;
}

double hourly::grossSalary() {
	double res = hours * hourlyrate;
	return res;
}

double hourly::calcSalary() {
	double res;
	res = hours * hourlyrate;
	res -= res * taxrate;
	return res;
}

void hourly::display() {
	cout << "Displaying Data for Hourly Employee:\n";
	cout << "Name: " << getname() << endl;
	cout << "Hours: " << gethours() << endl;
	cout << "Hourly Rate: " << gethourlyrate() << endl;
	cout << "Gross Salary: " << grossSalary() << endl;
	cout << "Tax Rate: " << gettaxrate() << "\t(" << gettaxrate() * 100 << "%)" << endl;
	cout << "Net Salary: " << calcSalary() << endl;
}

hourly::~hourly(){
	cout << "Hourly Destructor called1!\n";
}

/////////////////////////
//COMMISSIONED EMPLOYEE//
/////////////////////////

commissioned::commissioned() :employee() {
	sales = 0.0;
	comRate = 0.0;
}

commissioned::commissioned(const char* n, double taxrate, double sales, double rate) : employee(n, taxrate) {
	this->sales = sales;
	this->comRate = rate;
}

void commissioned::setsales(double sales) {
	this->sales = sales;
}

double commissioned::getsales() const {
	return this->sales;
}

void commissioned::setcomRate(double rate) {
	this->comRate = rate;
}

double commissioned::getcomRate() const {
	return this->comRate;
}

double commissioned::grossSalary() {
	double res = sales + (sales * comRate);
	return res;
}

double commissioned::calcSalary() {
	double res;
	res = sales + (sales * comRate);
	res -= res * taxrate;
	return res;
}

void commissioned::display() {
	cout << "Displaying Data for Commissioned Employee:\n";
	cout << "Name: " << getname() << endl;
	cout << "Sales: " << getsales() << endl;
	cout << "Commission Rate: " << getcomRate() << "\t(" << getcomRate() * 100 << "%)" << endl;
	cout << "Gross Salary: " << grossSalary() << endl;
	cout << "Tax Rate: " << gettaxrate() << "\t(" << gettaxrate() * 100 << "%)" << endl;
	cout << "Net Salary: " << calcSalary() << endl;
}

commissioned::~commissioned(){
	cout << "Commissioned Destructor called1!\n";
}

////////////////////
//FRIEND FUNCTIONS//
////////////////////

void showSalary(employee* emp[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Net Salary: " << emp[i]->calcSalary() << endl;
	}
}

void print(employee* emp[], int size) {
	for (int i = 0; i < size; i++) {
		emp[i]->display();
		cout << endl;
	}
}

void destruct(employee* emp[], int size) {
	for (int i = 0; i < size; i++) {
		delete emp[i];
	}
}