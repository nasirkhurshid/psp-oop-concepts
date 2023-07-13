#include <iostream>
#include <string.h>
using namespace std;

class mystring {
	char* n;
public:
	mystring();
	mystring(const char*);
	mystring(const mystring&);
	void setstring(const char*);
	char* getstring() const;
	virtual ~mystring();
};

class employee {
protected:
	mystring name;
	double taxrate;
public:
	employee();
	employee(const char*, double);
	void setname(const char*);
	char* getname() const;
	void settaxrate(double);
	double gettaxrate() const;
	friend void showSalary(employee* [], int);
	friend void print(employee* [], int);
	friend void destruct(employee* [], int);
	virtual double grossSalary() = 0;
	virtual double calcSalary()=0;
	virtual void display() = 0;
	virtual ~employee();
};

class salaried: public employee {
	double salary;
public:
	salaried();
	salaried(const char*, double, double);
	void setsalary(double);
	virtual double grossSalary();
	virtual double calcSalary();
	virtual void display();
	virtual ~salaried();
};

class hourly : public employee {
	double hours;
	double hourlyrate;
public:
	hourly();
	hourly(const char*, double, double, double);
	void sethours(double);
	double gethours() const;
	void sethourlyrate(double);
	double gethourlyrate() const;
	virtual double grossSalary();
	virtual double calcSalary();
	virtual void display();
	virtual ~hourly();
};

class commissioned : public employee {
	double sales;
	double comRate;
public:
	commissioned();
	commissioned(const char*, double, double, double);
	void setsales(double);
	double getsales() const;
	void setcomRate(double);
	double getcomRate() const;
	virtual double grossSalary();
	virtual double calcSalary();
	virtual void display();
	virtual ~commissioned();
};