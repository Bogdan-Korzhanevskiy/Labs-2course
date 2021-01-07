#include "Header.h"
int& test :: operator []( int index) {
	
	mass[index] = rand() % 20;
	cout << mass[index] << " ";
	if (mass[index] % 2 == 0)
	{
	return mass[index];
	}
	else {
		return mass[index] = 999;
		
	}
		

	
}

//ostream& operator<<(ostream& os, const test& a, int i)
//{
//	os << a[i];
//	return os;
//}
//
//istream& operator>>(istream& is, test& a) {
//	is >> a[i];
//	return is;
//}

//f<<a[7]
//f>>

//a[8];