#include "Ppvs.h"

ppvs::ppvs() {

	diam = 0;
	chast = 0;
}


ppvs::ppvs(int d, string a, float c, int b) {
	
	name = a;
	year = d;
	diam = c;
	chast = b;
}

ostream& operator<<(ostream& stream, ppvs& o1) {
	shapka();
	stream << "|" << setw(6) << o1.year << " |  ";
	stream << setw(22) << o1.name << " |";
	stream << setw(19) << o1.diam << " |";
	stream << setw(23) << o1.chast << "|" << endl;
	linebuild();
	return stream;
}

istream& operator>>(istream& stream, ppvs& o1) {
	cout << "Год, Научный руководитель, Диаметр, Частота: \n";
	stream >> o1.year;
	stream >> o1.name;
	stream >> o1.diam;
	stream >> o1.chast;
	return stream;
}


ppvs ppvs::operator + (ppvs& o1) {
	ppvs tr;
	int i, j;
	tr.name = name;
	tr.name = tr.name + o1.name;
	tr.year = year;
	tr.year = tr.year + o1.year;
	tr.diam = diam + o1.diam;
	tr.chast = chast + o1.chast;
	return tr;
}

int ppvs::operator == (ppvs& o1) {
	if (diam != o1.diam) { cout << "Данные экземпляры класса не равны."; _getch(); }
	else if (chast != o1.chast) { cout << "Данные экземпляры класса не равны."; _getch(); }
	else if (name != o1.name) { cout << "Данные экземпляры класса не равны."; _getch(); }
	else if (year != o1.year) { cout << "Данные экземпляры класса не равны."; _getch(); }
	else cout << "Экземпляры класса равны."; _getch();
	return 0;
}

ppvs  ppvs:: operator = (const ppvs& o1) {
	
	
	name = o1.name;
	year = o1.year;
	diam = o1.diam;
	chast = o1.chast;
	return o1;
}



void ppvs::setall(int b, string a, float c, int d) {
	name = a;
	year = b;
	diam = c;
	chast = d;
}

void ppvs::showall(void) {
	cout << year << " ";
	cout << name << " ";
	cout << diam << " ";
	cout << chast << " ";
}

void ppvs::getall(int b, string a, float& c, int& d)
{
	a = name;
	b = year;
	c = diam;
	d = chast;
	cout << b << " ";
	cout << a << " ";
	cout << c << " ";
	cout << d << " ";
	cout << "\n";
}