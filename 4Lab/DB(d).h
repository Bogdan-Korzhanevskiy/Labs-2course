#pragma once

#include "Ppvs.h"

class DB
{
public:
	DB(string title);
	~DB();
	friend ostream& operator <<(ostream& stream, DB& o1);

	int getCol();
	void add_rec(string name, float diam, int chast, int year);
	void del_rec();
	void sortDB();
	int col;
private:
	string title;
	ppvs* rows[12];
	//int col;
	bool sorted;
};