#include <iostream>
#include <conio.h>

//engine
#include "Object.h"
#include "Map.h"
#include "Point.h"

using namespace std;

int main()
{
	//size
	int x = 15;
	int y = 30;
	
	//positions
	Point startPos = Point{ 0, 0 };      //start postion

	//objects
	Object player = Object('p', 1, true, startPos);         // player
	Object stone = Object('@', 7, true);         // stone
	Object tree = Object('Y', 2,false);         // tree
	Object bg = Object('*', 2);             //background
	Map GameMap = Map(x, y);             //gamemap
	
	Point nextPos = startPos;

	GameMap.FillMap(bg);                 //filling map with bg
	GameMap.AddObject(player, player.getPosition()); //adding player

	GameMap.AddObject(stone, Point{ 5, 5 }); // adding stone
	GameMap.AddObject(tree, Point{ 7, 3 }); // adding tree


	bool isGame = true;                  //is game on?


	//gamecycle
	while (isGame)
	{
		GameMap.RenderMap(cout);          //Render map

		char button = _getch();            //getting input

		//processing input

		//move
		if (button == 'd')
		{
			nextPos.y++;
		}
		else if (button == 'a')
		{
			nextPos.y--;
		}
		else if (button == 's')
		{
			nextPos.x++;
		}
		else if (button == 'w')
		{
			nextPos.x--;
		}
		else if (button == 'q')
		{
			isGame = false;
		}

		if (GameMap.MoveObject(startPos, nextPos)) // if move was made
		{
			startPos = nextPos;
		}
		else
		{
			nextPos = startPos;
		}
		system("cls"); // clear the screen
	}

	system("pause");
	return 0;
}

//demonstration
/*Object obj = Object('p');
	Object obj1 = Object('*');
	Point point = Point{2, 3};

	Map gameMap = Map(10, 10);
	gameMap.AddObject(obj, point);
	gameMap.RenderMap(cout);
	system("pause");

	gameMap.FillMap(obj);
	gameMap.RenderMap(cout);
	system("pause");

	gameMap.AddObject(obj1, point);
	gameMap.RenderMap(cout);
	system("pause");

	gameMap.MoveObject(point, Point{ 0, 0 });
	gameMap.RenderMap(cout);
	system("pause");

	gameMap.ClearMap();
	gameMap.RenderMap(cout);
	system("pause");*/