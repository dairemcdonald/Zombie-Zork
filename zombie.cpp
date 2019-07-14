#include "zombie.h"

zombie::zombie()
{
   this->name = "Zombie";
   this->hp = 20;
   this->acc = 50;
   this->damage = 5;
}



void zombie::head(int dam)
{
 hp = hp-(dam * 1.4);
}

void zombie::arms(int dam)
{
 hp = hp-dam;
 acc = (acc * 0.8);
}

void zombie::legs(int dam)
{
 hp = hp-dam;
 damage = (damage * 0.8);
}

void zombie::torso(int dam)
{
    hp = hp - dam;
}
