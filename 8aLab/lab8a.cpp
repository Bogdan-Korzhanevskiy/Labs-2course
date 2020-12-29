#include "Class.h"

#include <iostream>


int main()
{
	int a1 = 5;
	int a2 = 7;

	double b1 = 4.45;
	double b2 = 6.84;

	float c1 = 9.5;
	float c11 = 5.3;

	MyClass<int> ob1(a1);
	MyClass<int> ob11(a2);
	cout << "ob1 = ";
	ob1.showValue();
	cout << "ob11 = ";
	ob11.showValue();
	cout << "ob1 + ob11 = ";
	(ob1 + ob11).showValue();
	cout << "---------------" << endl;

	MyClass<double> ob2(b1);
	MyClass<double> ob22(b2);
	cout << "ob2 = ";
	ob2.showValue();
	cout << "ob22 = ";
	ob22.showValue();
	cout << "ob2 + ob22 = ";
	(ob2 + ob22).showValue();
	cout << "---------------" << endl;

	MyClass<float> ob3(c1);
	MyClass<float> ob33(c11);
	cout << "ob3 = ";
	ob3.showValue();
	cout << "ob33 = ";
	ob33.showValue();
	cout << "ob3 + ob33 = ";
	(ob3 + ob33).showValue();
}