#include <string>
#include <iostream>
#include <assert.h>
#include "Test.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "ru");
	int arr[] = { 3,7,-1,-4,5 };
	int arrForSort[] = { 5,2,3,1,4 };
	int sortedArr[] = { 1,2,3,4,5 };

	int sumArr = 15;
	double arr1[] = { 1.2, 5.6, 2.3, 4.1, 7.9 };
	double arr2[] = { 1.2, 2.3, 4.1, 5.6, 7.9 };

	double minArr1 = 1.2;
	cout << "Сумма масива: " << Sum<int>(arr) << "\n";
	assert(sumArr == Sum<int>(arr));
	cout << "Первая проверка пройдена" << endl;

	cout << "min: " << Min<double>(arr1) << "\n";
	assert(minArr1 == Min<double>(arr1));
	cout << "Вторая проверка пройдена" << endl;

	cout << "Отсортированый масив:" << endl;
	
	sort<int>(arrForSort);

	for (int i = 0; i < size; i++) {
		cout << arrForSort[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		assert(arrForSort[i] == sortedArr[i]);
	}
	
	cout << "Третья проверка пройдена" << endl;
	sort<double>(arr1);
	for (int i = 0; i < size; i++) {
		assert(arr1[i] == arr2[i]);
	}
	for (int i = 0; i < size; i++) {
		cout << arr1[i] << " ";
	}
	return 0;
}