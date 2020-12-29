#include "service.h"

serv :: serv() {
	name = "zero";
	type = "zero";
	price1 = 0;
	price2 = 0;
}
serv::serv(string name, string type, double price1, double price2) {
	this->name = name;
	this->type = type;
	this->price1 = price1;
	this->price2 = price2;
}

void  set (serv& a, string& name, string& type, double& price1, double& price2) {
	
	a.name = name;
	a.type = type;
	a.price1 = price1;
	a.price2 = price2;

}

void  show(serv* obj) {
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "|  Наименование  |  Единица измерения  |  Стоимость за единицу  |  Стоим. расход. мат. за ед.  |" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << setw(16) << obj[i].name << "|" << setw(21) << obj[i].type << "|" << setw(24) << obj[i].price1 << "|" << setw(30) << obj[i].price2 << "|" << endl;
	}
}
void sort(serv* obj) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (obj[i].name < obj[j].name)
				swap(obj[i], obj[j]);
		}
	}
	show( obj);
}