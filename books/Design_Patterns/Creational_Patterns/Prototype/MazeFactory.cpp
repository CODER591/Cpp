#include "MazeFactory.h"
#include "Maze.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"

MazeFactory* MazeFactory::_instance = 0;

MazeFactory::MazeFactory()
{}

//MazeFactory* MazeFactory::Instance () {
//    if (_instance == 0) {
//        _instance = new MazeFactory;
//    }
//    return _instance;
//}

Maze* MazeFactory::MakeMaze() const
{
    return new Maze;
}

Wall* MazeFactory::MakeWall() const
{
    return new Wall;
}

Room* MazeFactory::MakeRoom(int n) const
{
    return new Room(n);
}

Door* MazeFactory::MakeDoor(Room* r1, Room* r2) const
{
    return new Door(r1, r2);
}
