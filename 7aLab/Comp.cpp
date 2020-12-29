#include "Comp.h"
Comp::Comp() {
	a = 0;
	b = 0;
	z = "";
}

void Comp::setZ() {
	ostringstream ss;
	ss << "" << a << '+' << b << 'i';
	z = ss.str();
}

Comp::Comp(int a, int b)
{
	this->a = a;
	this->b = b;
	setZ();
}

string Comp::getZ() {
	return z;
}