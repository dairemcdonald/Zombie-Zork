#include "player.h"

player::player()
{
  this->name = "player";
  this->hp = 150;
  this->acc = 50;
}

void player::hit(int dam)
{
    hp = hp- dam;
}

void player::addHealth(int addHealth)
{
    if(hp + addHealth < 150)
        hp += addHealth;
    else
        hp = 150;
}

