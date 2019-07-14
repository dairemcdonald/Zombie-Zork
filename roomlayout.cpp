#include "roomlayout.h"
#include <sstream>
#include <ctime>
using namespace std;

roomLayout::roomLayout()
{
    srand ( time(NULL) );
    for(int i = 0; i < 10; i ++)
        for(int j = 0; j < 10; j++)
            possibleRoomLocations[i][j] = "0 0 0 0";
    possibleRoomLocations[5][5] = "1 1 1 1";
    lastRoomIndexI = 5;
    lastRoomIndexJ = 5;

}
string roomLayout::addRoom(string directionGoing)
{
        int exitCount = 0;
        bool canMoveEast = true;
        bool canMoveWest = true;
        bool canMoveNorth = true;
        bool canMoveSouth = true;
        string result;

        string newRoomExits[4];

        int newRoomIndexI;
        int newRoomIndexJ;

        for(int i = 0; i < 4; i ++)
            newRoomExits[i] = "0";

        if(directionGoing == "north")
        {
            newRoomExits[1] = "1";
            newRoomIndexI = lastRoomIndexI - 1;
            newRoomIndexJ = lastRoomIndexJ;
        }
        if(directionGoing == "south")
        {
            newRoomExits[0] = "1";
            newRoomIndexI = lastRoomIndexI + 1;
            newRoomIndexJ = lastRoomIndexJ;
        }
        if(directionGoing == "east")
        {
            newRoomExits[3] = "1";
            newRoomIndexI = lastRoomIndexI;
            newRoomIndexJ = lastRoomIndexJ + 1;
        }
        if(directionGoing == "west")
        {
            newRoomExits[2] = "1";
            newRoomIndexI = lastRoomIndexI;
            newRoomIndexJ = lastRoomIndexJ - 1;
        }

        //check surrounding rooms
        if(newRoomIndexI -1 > 0) //going north
        {
            if(possibleRoomLocations[newRoomIndexI -1][newRoomIndexJ] != "0 0 0 0")
            {
                newRoomExits[0] = "1";

            }
        }
        else
        {
            canMoveNorth = false;
        }

        if(newRoomIndexI +1 < 9) //going south
        {
            if(possibleRoomLocations[newRoomIndexI + 1][newRoomIndexJ] != "0 0 0 0")
            {
                newRoomExits[1] = "1";
            }
        }
        else
        {
            canMoveSouth = false;
        }
        if(newRoomIndexJ -1 > 0) //going west
        {
            if(possibleRoomLocations[newRoomIndexI][newRoomIndexJ - 1] != "0 0 0 0")
            {
                newRoomExits[3] = "1";
            }
        }
        else
        {
            canMoveWest = false;
        }
        if(newRoomIndexJ +1 < 9) //going east
        {
            if(possibleRoomLocations[newRoomIndexI][newRoomIndexJ + 1] != "0 0 0 0")
            {
                newRoomExits[2] = "1";
            }
        }
        else
        {
            canMoveEast = false;
        }

        exitCount++;

        //create random exits if they can be made.. get how many possible exits can be made
        bool finished = false;
        while(!finished)
        {

                int rand_num;
                int lowest = 1;
                int range = 1 + 1;
                if(canMoveEast == true && (newRoomExits[2] != "1"))
                {
                    rand_num = lowest + rand() % range;
                    if(rand_num == 1)
                    {
                        newRoomExits[2] = "1";
                        exitCount++;
                    }
                    else
                        newRoomExits[2] = "0";
                }
                if(canMoveWest == true && (newRoomExits[3] != "1"))
                {
                    rand_num = lowest + rand() % range;
                    if(rand_num == 1)
                    {
                        newRoomExits[3] = "1";

                        exitCount++;
                    }
                    else
                        newRoomExits[3] = "0";
                }
                if(canMoveNorth == true && (newRoomExits[0] != "1"))
                {
                    rand_num = lowest + rand() % range;
                    if(rand_num == 1)
                    {
                        newRoomExits[0] = "1";
                        exitCount++;
                    }
                    else
                        newRoomExits[0] = "0";
                }
                if(canMoveSouth == true && (newRoomExits[1] != "1"))
                {
                    rand_num = lowest + rand() % range;
                    if(rand_num == 1)
                    {

                        exitCount++;
                        newRoomExits[1] = "1";
                    }
                    else
                        newRoomExits[1] = "0";
                }

              if(exitCount >= 2)
              {
                  finished = true;
              }
        }




        if(possibleRoomLocations[newRoomIndexI][newRoomIndexJ] == "0 0 0 0") //if the room you are trying to enter is new
        {
            newRoom = true;
            lastRoomIndexI = newRoomIndexI;
            lastRoomIndexJ = newRoomIndexJ;
            if(canMoveWest == false)
                newRoomExits[3] = "0";
            result = newRoomExits[0] + " " + newRoomExits[1] + " " +newRoomExits[2] + " " + newRoomExits[3];

            possibleRoomLocations[newRoomIndexI][newRoomIndexJ] = result;
            currentResult = result;
            roomCount += 1;
            return result;

        }
        else //this room has already been created so return the information on this room
        {
            newRoom = false;
            lastRoomIndexI = newRoomIndexI;
            lastRoomIndexJ = newRoomIndexJ;
            currentResult = result;
            return possibleRoomLocations[newRoomIndexI][newRoomIndexJ];
        }
}

int roomLayout::getIndexI()
{
    return lastRoomIndexI;
}
int roomLayout::getIndexJ()
{
    return lastRoomIndexJ;
}
string roomLayout::getCurrentResult()
{
    return currentResult;
}

int roomLayout::getRoomCount()
{
    return roomCount;
}


bool roomLayout::isNewRoom()
{
    return newRoom;
}
