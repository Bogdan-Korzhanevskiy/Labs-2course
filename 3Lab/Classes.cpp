#include "Classes.h"
using namespace std;

B1::B1(int b1)
{
	this->b1 = b1;
}

void B1::show() {
	cout << "B1 " << b1 << endl;
}

B1::~B1()
{
	cout << "D(B1)" << endl;
}

D1::D1(int b1, int d1) : B1(b1)
{
	this->d1 = d1;
}

void D1::show() {
	B1::show();
	cout << "D1 " << d1 << endl;
}

D1::~D1()
{
	cout << "D(D1)" << endl;
}


D2::D2(int b1,  int d1, int d2 ) :  D1( b1, d1) {
	this->d2 = d2;
}

void D2::show() {
	//B1::show();
	D1::show();
	cout << "D2 " << d2 << endl;
}


D2::~D2()
{
	cout << "D(D2)" << endl;
}

B2::B2(int b2)
{
	this->b2 = b2;
}

void B2::show() {
	cout << "B2 " << b2 << endl;
}

B2::~B2()
{
	cout << "D(B2)" << endl;
}


D3::D3(int b1, int d1, int d2, int d3, int b2) : B2(b2), D2( b1 , d1, d2 ) 
{
	this->d3 = d3;
}

void D3::show() {
	B2::show();
	//D1::show();
	D2::show();
	//B1::show();

	cout << "D3 " << d3 << endl;
}


D3::~D3()
{
	cout << "D(D3)" << endl;
}