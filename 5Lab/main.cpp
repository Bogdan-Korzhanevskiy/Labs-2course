#include "Header.h"

 

int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	fstream fs;
	test a;
	int b;
	string fname = "dbfile.txt";
	while (true) {


		cout << "|-------------------------------------------|\t" << endl;
		cout << "|*******************����********************|\t" << endl;
		cout << "|-------------------------------------------|\t" << endl;
		cout << "|�������� �������� �������� �� ������� ����:|\t" << endl;
		cout << "|1 � �������� �������� � ����               |\t" << endl;
		cout << "|2 � �������� ������� �� �����              |\t" << endl;
		cout << "|3 - ���������� ���������                   |\t" << endl;
		cout << "|-------------------------------------------|\t" << endl;
		int p;
		cin >> p;
		switch (p) {
		case 1: 
			fs.open(fname, fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
			{
				cout << "������ ��� �������� �����!" << endl;
			}
			else {

				cout << "���� ������� ������ ��� ������ !" << endl;
				///////////������

				for (int i = 0; i < N; i++) {
					fs << a[i] << "\n";
				}


				cout << endl;
				fs.close();

			}
			
		
			//fs.open(fname, fstream::in | fstream::out | fstream::app);
			//if (!fs.is_open())
			//{
			//	cout << "������ ��� �������� �����!" << endl;
			//}
			//else {

			//	cout << "���� ������� ������ ��� ������ !" << endl;
			//	///////////������
			//	/*for (int i = 0; i < N; i++) {
			//		a[i] = rand() % 20;
			//		cout << a[i] << " ";
			//		if (a[i] % 2 == 0) {
			//			fs << a[i] << "\n";
			//		}
			//	}*/

			//	cout << endl;
			//	fs.close();

			//}
			break;
		
		
		/*case 2: 
			fs.open(fname, fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
			{
				cout << "������ ��� �������� �����!" << endl;
			}
			else {

				cout << "���� ������� ������ ��� ������!" << endl;

				while (true) {
					fs >> b;
					if (fs.eof()) {
						break;
					}
					if (b % 4 == 0) {
						cout << b << " ";
					}
				}
				cout << endl;
				fs.close();

				
			}
			break;*/

		
		case 3: 
			return 0;
			
		

		default: 
			cout << "�������� �����" << endl;
			_getch();
			break;
		

		}
		system("pause");
		
	}
	return 0;
}

