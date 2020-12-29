#include "Ppvs.h"
#include "DB(d).h"



int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода (локализация)
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода (локализация)
    setlocale(LC_ALL, "rus");
    string name;
    float diam;
    int chast;
    int year;

    DB* tmp = new DB("\nБАЗА ДАННЫХ =1\n");


    while (true) {
        cout << "В базе: " << tmp->col/*tmp->getCol()*/ << " записей на данный момент" << endl;
        cout << "|-------------------------------------------|\t" << endl;
        cout << "|*******************МЕНЮ********************|\t" << endl;
        cout << "|-------------------------------------------|\t" << endl;
        cout << "|Выбирете желаемое действие из перечня ниже:|\t" << endl;
        cout << "|1 – Ввод информации о ППВС вручную         |\t" << endl;
        cout << "|2 – Ввод  готовой информации о ППВС        |\t" << endl;
        cout << "|3 - Удаление последней записи из БД        |\t" << endl;
        cout << "|4 - Сортировка информации в БД             |\t" << endl;
        cout << "|5 - Вывод БД на экран                      |\t" << endl;
        cout << "|6 - Завершение програмы                    |\t" << endl;
        cout << "|-------------------------------------------|\t" << endl;

       
        cout << "Введите номер желаемого действия: ";
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
          
            cout << "Год, Научный руководитель, Диаметр антенны (м), Рабочая частота (МГц): \n";
            cin >> year;
            cin >> name;
            cin >> diam;
            cin >> chast;
            tmp->add_rec(name, diam, chast, year);

            break;
        case 2:
        
            tmp->add_rec("Дрейк", 26, 1420, 1960);
            tmp->add_rec("Троицкий", 14, 1875, 1970);
            tmp->add_rec("Хоровиц", 300, 1665, 1978);
           
            break;
        case 3:
            tmp->del_rec();
            break;
        case 4:

            tmp->sortDB();

            break;
        case 5:
           
            cout << *tmp;


            break;
        case 6:

            system("cls");
       
            return 0;
            break;
        }



    }
}