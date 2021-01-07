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
		cout << "|*******************МЕНЮ********************|\t" << endl;
		cout << "|-------------------------------------------|\t" << endl;
		cout << "|Выбирете желаемое действие из перечня ниже:|\t" << endl;
		cout << "|1 – Случайно записать в файл               |\t" << endl;
		cout << "|2 – Случайно считать из файла              |\t" << endl;
		cout << "|3 - Завершение программы                   |\t" << endl;
		cout << "|-------------------------------------------|\t" << endl;
		int p;
		cin >> p;
		switch (p) {
		case 1: 
			fs.open(fname, fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
			{
				cout << "Ошибка при открытии файла!" << endl;
			}
			else {

				cout << "Файл успешно открыт для записи !" << endl;
				///////////запись

				for (int i = 0; i < N; i++) {
					fs << a[i] << "\n";
				}


				cout << endl;
				fs.close();

			}
			
		
			//fs.open(fname, fstream::in | fstream::out | fstream::app);
			//if (!fs.is_open())
			//{
			//	cout << "Ошибка при открытии файла!" << endl;
			//}
			//else {

			//	cout << "Файл успешно открыт для записи !" << endl;
			//	///////////запись
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
				cout << "Ошибка при открытии файла!" << endl;
			}
			else {

				cout << "Файл успешно открыт для чтения!" << endl;

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
			cout << "Неверный вызов" << endl;
			_getch();
			break;
		

		}
		system("pause");
		
	}
	return 0;
}

