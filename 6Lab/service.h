#pragma once

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#define N 3
using namespace std;

class serv {

public:
	string name;
	string type;
	double price1;
	double price2;

	serv();
	serv(string name, string type, double price1, double price2);
};

void set(serv& a, string& name, string& type, double& price1, double& price2);
void show(serv* obj);
void sort(serv* obj);