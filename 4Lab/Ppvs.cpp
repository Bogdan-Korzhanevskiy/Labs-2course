#include "Ppvs.h"

using namespace std;

ppvs::ppvs() {
	name = "Имя";
	diam = 0;
	chast = 0;
	year = 0;

}

ppvs::ppvs(string name, float diam, int chast, int year) {
	this->name = name;
	this->diam = diam;
	this->chast = chast;
	this->year = year;
}


void ppvs::set(string name, float diam, int chast, int year)
{
	this->name = name;
	this->diam = diam;
	this->chast = chast;
	this->year = year;
}

void ppvs::get(string name, float& diam, int& chast, int year)
{

	name = this->name;
	diam = this->diam;
	chast = this->chast;
	year = this->year;

}

ostream& operator <<(ostream& stream, ppvs& o1) {

	//buildHead();
	stream << "|" << setw(5) << o1.year << "  |  ";
	stream << setw(21) << o1.name << "  |";
	stream << setw(18) << o1.diam << "  |";
	stream << setw(23) << o1.chast << "|" << endl;
	buildLine();
	return stream;
}

istream& operator >>(istream& stream, ppvs& o1) {

	cout << "Год, Научный руководитель, Диаметр антенны (м), Рабочая частота (МГц): \n";
	stream >> o1.name;
	stream >> o1.diam;
	stream >> o1.chast;
	stream >> o1.year;
	return stream;
}

ppvs ppvs::operator = (ppvs& o1) {

	name = o1.name;
	diam = o1.diam;
	chast = o1.chast;
	year = o1.year;

	return *this;
}

int operator==(ppvs& o1, ppvs& o2) {

	if (o2.name != o1.name) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.diam != o1.diam) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.chast != o1.chast) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.year != o1.year) cout << "Данные экземпляры класса не равны." << endl;
	else cout << "Экземпляры класса равны." << endl;
	return 0;
}

ppvs ppvs::operator+(ppvs& o1) {
	name = name + o1.name;
	diam = diam + o1.diam;
	chast = chast + o1.chast;
	year = year + o1.year;
	return *this;
}

ppvs  ppvs ::operator()(string name, float diam, int chast, int year){

	this->name = name;
	this->diam = diam;
	this->chast = chast;
	this->year = year;
	return *this;
}

int ppvs::operator[](int i) {
	int length;
	length = name.length();
	return length;
}

string ppvs::retName() {
	return name;
}

void showAll(ppvs* ob) {
	buildHead();
	for (int i = 0; i < N; i++)
	{
		cout << ob[i];

	}
}

bool check(int a) {
	if (a < N && a >= 0)
		return true;
	return false;
}

void buildHead() {
	printf("|------------------------------------------------------------------------------|\n");
	printf("|----------------------Проекты поиска внеземных сигналов-----------------------|\n");
	printf("|------------------------------------------------------------------------------|\n");
	printf("|  Год  |   Научный руководитель  | Диаметр антенны (м)| Рабочая частота (МГц) |\n");
	printf("|-------|-------------------------|--------------------|-----------------------|\n");

}

void buildLine() {
	printf("|-------|-------------------------|--------------------|-----------------------|\n");
}
