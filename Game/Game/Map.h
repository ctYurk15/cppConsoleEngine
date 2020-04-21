#pragma once

#include <iostream>
#include <vector>

#include "Object.h"
#include "Point.h"

using namespace std;

class Map
{
private:
	int x = 0;
	int y = 0;
	int defaultColour = 7;

	Object** map;
	vector<Object> underObjects;

public:
	//constructors
	Map();
	Map(int, int);
	Map(int, int, int);

	//objects
	void AddObject(Object, Point);
	bool MoveObject(Point, Point);

	//map
	void RenderMap(ostream&);
	void FillMap(Object);
	void ClearMap();

	//other
	bool correctPoint(Point);

	~Map();
};

