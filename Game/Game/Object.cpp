#include "Object.h"

#include <iostream>

using namespace std;

Object::Object()
{
	objectUnder.push_back(NULL);
}

Object::Object(char _texture)
{
	//objectUnder.push_back(NULL);
	texture = _texture;
}

Object::Object(char _texture, int _color)
{
	objectUnder.push_back(NULL);
	texture = _texture;
	color = _color;
}

Object::Object(char _texture, int _color, bool isSolid)
{
	objectUnder.push_back(NULL);
	texture = _texture;
	solid = isSolid;
	color = _color;
}

Object::Object(char _texture, int _color, bool isSolid, Point position)
{
	objectUnder.push_back(NULL);
	texture = _texture;
	solid = isSolid;
	pos = position;
	color = _color;
}

void Object::setTexture(char _texture)
{
	texture = _texture;
}

void Object::SetPosition(Point newPos)
{
	pos = newPos;
}

bool Object::isSolid()
{
	return solid;
}

Point Object::getPosition()
{
	return pos;
}

char Object::GetTexture()
{
	return texture;
}

void Object::SetObjectUnder(Object _objectUnder)
{
	objectUnder[0] = _objectUnder;

}

void Object::Print(ostream& outputStream)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	outputStream << texture;
}

Object Object::getObjectUnder()
{
	return objectUnder[0];
}


Object::~Object()
{
}
