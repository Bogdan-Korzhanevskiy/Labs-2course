#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

class Comp
{
public:
	Comp();
	Comp(int a, int b);
	
	string getZ();
private:
	void setZ();
	int a;  //1.1
	int b;  //2.2       1.1 +2.2i
	string z = "";
};