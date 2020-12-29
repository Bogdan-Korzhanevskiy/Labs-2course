#pragma once

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include "Functions.h"

#define N 3
using namespace std;

class ppvs {
private:
	string name; //имя
	float diam; // диаметр
	int chast; // частота
	int year; // год
	
	friend ostream& operator<<(ostream& stream, ppvs& o1);
	friend istream& operator>>(istream& stream, ppvs& o1);

	
public:
	ppvs();
    ppvs(int d, string a, float c, int b);
	void setall(int b, string a, float, int);
	void getall(int b, string a, float& c, int& d);
	void showall(void);
    ppvs operator + (ppvs& o1);
	ppvs operator = (const ppvs& o1);
	int  operator == (ppvs& o1);
};