#include <Windows.h>
#include "Ppvs.h"
#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� ����� (�����������)
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������ (�����������)
	

			string n;
			int t = 0;
			float s;
			int h;
			short i;
			short q , q1;

			ppvs obj[N] = { ppvs(1960, "�����", 26, 1420),
					   ppvs(1970, "��������", 14, 1875),
					   ppvs(1978, "�������", 300, 1665) };
			cout <<  "���, ������� ������������, �������, �������: \n";
			for (i = 0; i < N; i++) {
				obj[i].showall();
				cout << "\n";
			}

			cout << "\n���������� ��������� ������������ '='.\n";
			cout << "������� ������ ����������� ������: ���������� � ����������>\n";
			cin >> q;
			cin >> q1;
			q--;
			q1--;
			if (isvalid(q, q1) != 0) exit(-1);
			obj[q] = obj[q1];

			cout << "���, ������� ������������, �������, �������: \n";
			for (i = 0; i < N; i++) {
				obj[i].showall();
				cout << "\n";
			}

			cout << "\n���������� ��������� ������������ '=='.\n";
			cout << "������� ������ ����������� ������, ������� ���� ��������>\n";
			cin >> q;
			cin >> q1;
			q--;
			q1--;
			if (isvalid(q, q1) != 0) exit(-1);
			obj[q] == obj[q1];

			cout << "\n���������� ��������� ����� '+'.\n";
			cout << "������� 1 ����� ����������� ������, ������� ���� �������>\n";
			cin >> q;
			cout << "������� 2 ����� ����������� ������, ������� ���� �������>\n";
			cin >> q1;
			q--;
			q1--;
			ppvs temp;
			if (isvalid(q, q1) != 0) exit(-1);
			temp = obj[q] + obj[q1];
			cout << "���, ������� ������������, �������, �������: \n";
			temp.getall(t, n, s, h);

			cout << "\n���������� ��������� ���������� ����� '>>'.";
			cout << "\n������� ����� ���������� ������: ";
			cin >> q;
			q--;
			if ((q > N - 1) || (q < 0)) 
			{ 
			cout << "������! ���������� � ����� �������� �� ����������."; 
			_getch();
			exit(-1); 
			}
			cin >> obj[q];

			cout << "\n���������� ��������� ���������� ������ '<<'.";
			cout << "\n������� ����� ���������� ������: ";
			cin >> q;
			q--;
			if ((q > N - 1) || (q < 0)) { cout << "������! ���������� � ����� �������� �� ����������."; 
			_getch();
			exit(-1); }
			cout << obj[q];
			_getch();

			return 0;
	}