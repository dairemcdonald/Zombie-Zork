#include "mutant.h"

mutant::mutant()
{
    this->name = "mutant";
    this->hp = 15;
    this->acc = 60;
    this->damage = 8;
 }



 void mutant::head(int dam)
 {
  hp = hp-(dam * 1.25);
 }

 void mutant::arms(int dam)
 {
  hp = hp-dam;
  acc = (acc * 0.8);
 }

 void mutant::legs(int dam)
 {
  hp = hp-dam;
  damage = (damage * 0.8);
 }

 void mutant::torso(int dam)
 {
     hp = hp - dam;
 }
