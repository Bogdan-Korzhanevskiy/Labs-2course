#include "Ppvs.h"
#include "DB(d).h"



int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� ����� (�����������)
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������ (�����������)
    setlocale(LC_ALL, "rus");
    string name;
    float diam;
    int chast;
    int year;

    DB* tmp = new DB("\n���� ������ =1\n");


    while (true) {
        cout << "� ����: " << tmp->col/*tmp->getCol()*/ << " ������� �� ������ ������" << endl;
        cout << "|-------------------------------------------|\t" << endl;
        cout << "|*******************����********************|\t" << endl;
        cout << "|-------------------------------------------|\t" << endl;
        cout << "|�������� �������� �������� �� ������� ����:|\t" << endl;
        cout << "|1 � ���� ���������� � ���� �������         |\t" << endl;
        cout << "|2 � ����  ������� ���������� � ����        |\t" << endl;
        cout << "|3 - �������� ��������� ������ �� ��        |\t" << endl;
        cout << "|4 - ���������� ���������� � ��             |\t" << endl;
        cout << "|5 - ����� �� �� �����                      |\t" << endl;
        cout << "|6 - ���������� ��������                    |\t" << endl;
        cout << "|-------------------------------------------|\t" << endl;

       
        cout << "������� ����� ��������� ��������: ";
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
          
            cout << "���, ������� ������������, ������� ������� (�), ������� ������� (���): \n";
            cin >> year;
            cin >> name;
            cin >> diam;
            cin >> chast;
            tmp->add_rec(name, diam, chast, year);

            break;
        case 2:
        
            tmp->add_rec("�����", 26, 1420, 1960);
            tmp->add_rec("��������", 14, 1875, 1970);
            tmp->add_rec("�������", 300, 1665, 1978);
           
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