#include "Name.h"
#include "Number.h"

extern vector<Name> ob1;
extern vector<Number> ob2;
map<string, unsigned long int> arr;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    for (int i = 0; i < ob1.size(); i++) // заполнение map
    {
        arr.emplace(ob1[i].getName(), ob2[i].getNumber());
    }
    

    while (true) {
        int menu;
        string key;
        char letter;

        cout << "1. Вывести map" << endl;
        cout << "2. Поиск по ключу" << endl;
        cout << "3. Напечатать всех, у кого имя начинается на букву: " << endl;
        cout << "4. Удалить всех, у кого имя начинается на букву: " << endl;

        cin >> menu;

        switch (menu) {
        case 1:
           
            show(arr);
            
            break;
        case 2:
            cout << "Введите ключ > ";
            cin >> key;
            findByKey(arr, key);
            break;
        case 3:
            cout << "Введите букву > ";
            cin >> letter;
            findAllByLetter(arr, letter);
            break;
        case 4:
            cout << "Введите букву > ";
            cin >> letter;
            
            deleteAllByLetter(letter);
            break;
        default:
            exit(0);
            break;
        }
        system("pause");
        

    }
}