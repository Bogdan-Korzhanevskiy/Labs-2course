#include "service.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	serv obj[N];

	string name;
	string type;
	double price1;
	double price2;


	for (int i = 0; i < N; i++)
	{
		cout << "�������: ������������, ������� ���������, ��������� �� �������, ��������� ��������� ���������� �� �������" << endl;
		cin >> name;
		cin >> type;
		cin >> price1;
		cin >> price2;
		set(obj[i], name, type, price1, price2);
	}

	show(obj);
	cout << endl;
	cout << "��������������� �������: " << endl;
	sort(obj);
}