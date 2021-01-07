#pragma once
#ifndef __FUNC__H
#define __FUNC__H
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include<ctime>
#define N 15

using namespace std;

class test {
private:
	int mass[N];
public:
	test() {}
	 int& operator []( int index);
	
	 /*friend ostream& operator<<(ostream& os, const test& point);
	 friend istream& operator>>(istream& is, test& p);*/
};

#endif 