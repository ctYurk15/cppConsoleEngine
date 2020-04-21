#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

#include "Point.h"

using namespace std;

class Object
{
private:
	char texture = ' ';
	bool solid = false;
	int color = 1;
	Point pos{0, 0};
	vector<Object> objectUnder;


public:
	//constructors
	Object();
	Object(char);
	Object(char, int);
	Object(char, int, bool);
	Object(char, int, bool, Point);

	//setting vars
	void setTexture(char);
	void SetPosition(Point);

	//getting vars
	bool isSolid();
	Point getPosition();
	char GetTexture();

	//other
	void SetObjectUnder(Object);
	void Print(ostream&);
	Object getObjectUnder();

	~Object();
};

