#include "Map.h"



Map::Map()
{
}

Map::Map(int _x, int _y)
{
	//setting sizes
	if (_x > 0 && _y > 0)
	{
		x = _x;
		y = _y;
	}

	//creating empty map
	map = new Object*[x];
	for (int i = 0; i < x; i++)
	{
		map[i] = new Object[y];
	}
}

Map::Map(int _x, int _y, int _defaultColour)
{
	//setting sizes
	if (_x > 0 && _y > 0)
	{
		x = _x;
		y = _y;
	}

	//creating empty map
	map = new Object*[x];
	for (int i = 0; i < x; i++)
	{
		map[i] = new Object[y];
	}

	//color
	defaultColour = _defaultColour;
}

void Map::AddObject(Object obj, Point pos)
{
	if (correctPoint(pos))
	{
		obj.SetObjectUnder(map[pos.x][pos.y]);
		map[pos.x][pos.y] = obj;
		obj.SetPosition(pos);
	}
}

bool Map::MoveObject(Point from, Point to)
{
	bool moved = false;

	if (correctPoint(from) && correctPoint(to))
	{
		if (!map[to.x][to.y].isSolid())
		{
			
			Object toOBJ = map[to.x][to.y]; // creating clone of obj with to position
			Object fromOBJ = map[from.x][from.y]; // creating clone of obj with from position
			map[to.x][to.y] = map[from.x][from.y]; // setting obj with from position to to position
			map[from.x][from.y] = fromOBJ.getObjectUnder(); // setting to from position object under from from position
			map[to.x][to.y].SetObjectUnder(toOBJ); // setting to moved obj obj from to position
			map[to.x][to.y].SetPosition(to); // setting correct position
			moved = true; // all was correct
		}
	}

	return moved;
}

void Map::RenderMap(ostream& out)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			map[i][j].Print(out);
		}
		out << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultColour);
}

void Map::FillMap(Object obj)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			map[i][j] = obj;
			map[i][j].SetPosition(Point{ i, j });
		}
	}
}

void Map::ClearMap()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			map[i][j] = Object();
			map[i][j].SetPosition(Point{ i, j });
		}
	}
}

bool Map::correctPoint(Point pos)
{
	bool result = false;

	//if pos is bigger thst 0 and less than borders
	if (pos.x >= 0 && pos.y >= 0 && pos.x < x && pos.y < y)
	{
		result = true;
	}

	return result;
}

Map::~Map()
{
}
