#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

class B1 {
public:
	B1(int b1);
	~B1();
	virtual void show();
private:
	int b1;
};

class D1 : public B1
{
public:
	D1( int b1 , int d1 );
	~D1();
	virtual void show() override;

private:
	int d1;
};

class D2 :  private D1
{
public:
	D2( int b1,  int d1, int d2 );
	~D2();
	virtual void show() override;

private:
	int d2;
};

class B2 {
public:
	B2(int b2);
	~B2();
	virtual void show();
private:
	int b2;
};

class D3 : public D2, private B2
{
public:
	D3( int b1 , int d1 , int d2 , int d3 , int b2);
	~D3();
	virtual void show()override;

private:
	int d3;
};