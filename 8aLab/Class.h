#pragma once
#include <iostream>

using namespace std;

template<typename T>

class MyClass
{
public:
	MyClass();
	MyClass(T value);

	MyClass<T> operator + (MyClass<T>& ob);
	void showValue();
private:
	T value;
};

template<typename T>
MyClass<T> MyClass<T>::operator+(MyClass<T>& ob) {
	MyClass temp;
	temp.value = this->value + ob.value;
	return temp;
}

template<typename T>
MyClass<T>::MyClass() {
	value = 0;
}

template<typename T>
MyClass<T>::MyClass(T value) {
	this->value = value;
}

template<typename T>
void MyClass<T>::showValue() {
	cout << value << endl;
}