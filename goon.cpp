#include "goon.h"

goon::goon()
{
    this->name = "goon";
    this->hp = 10;
    this->acc = 70;
    this->damage = 3;
 }

 void goon::head(int dam)
 {
  hp = hp-(dam * 1.25);
 }

 void goon::arms(int dam)
 {
  hp = hp-dam;
  acc = (acc * 0.8);
 }

 void goon::legs(int dam)
 {
  hp = hp-dam;
  damage = (damage * 0.8);
 }

 void goon::torso(int dam)
 {
     hp = hp - dam;
 }
