#include "basestats.h"

//string name;
int hp;
int accuracy ;
int damage;
bool isBurst = false;
bool isDead = false;
basestats::basestats()
{

}

QString basestats::getName()
{
    return QString::fromStdString(name);
}

int basestats::getHP()
{

    return hp;
}


int basestats::getAccuracy()
{
    return acc;
}

int basestats::getDamage()
{
    return damage;
}

bool basestats::isAlive()
{
    return isDead;
}
void basestats::setDead()
{
    isDead = true;
}
void basestats::setHP(int newHp)
{
    hp = newHp;
}

