#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#define N 3

using namespace std;


class ppvs {
private:
	string name; //Научный руководитель
	float diam; //Диаметр
	int chast;  // Частота
	int year;  //Год

	friend ostream& operator <<(ostream& stream, ppvs& o1);
	friend istream& operator >>(istream& stream, ppvs& o1);

public:
	ppvs();
	ppvs(string name,float diam, int chast, int year);
	void set(string name, float diam, int chast, int year);
	void get(string name, float& diam, int& chast, int year);


	ppvs operator = (ppvs& o1);
	friend int operator == (ppvs& o1, ppvs& o2);
	ppvs operator + (ppvs& o1);
	ppvs operator()(string name, float diam, int chast, int year);
	int operator[](int i);
	string retName();//дописать inline
};

bool check(int a);

void showAll(ppvs* ob);

void buildHead();
void buildLine();