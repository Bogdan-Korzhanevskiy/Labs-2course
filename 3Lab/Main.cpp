#include "Classes.h"
using namespace std;


int main() {
	D3 obd3(-7,8,13,9,22);
	//b1=-7  b2 =22   d1=8  d2=13  d3= 9     

	D2 obd2(6, 8, 1);
	cout << "Object obd3 of class D3 with parametrs 5, -1, 3, -4, 0" << endl;
	obd3.show();
	cout << "Object obd2 of class D2 with parametrs 6, 8, 1" << endl;
	obd2.show();
}