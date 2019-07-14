#ifndef ROOMLAYOUT_H
#define ROOMLAYOUT_H
#include <string>
#include "loot.h"
#include "knife.h"
#include "grenade.h"
using namespace std;

class roomLayout
{
public:
    roomLayout();
    string addRoom(string directionGoing);
    string possibleRoomLocations[10][10];
    string lastRoom;
    int lastRoomIndexI = 0;
    int lastRoomIndexJ = 0;
    int getIndexI();
    int getIndexJ();
    string currentResult;
    string getCurrentResult();
    int roomCount = 0;
    int getRoomCount();
    bool newRoom;
    bool isNewRoom();

};

#endif // ROOMLAYOUT_H
