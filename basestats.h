#ifndef basestats_H
#define basestats_H
#include <QString>
#include <string>
using namespace std;

class basestats
{
public:
    string name;
    int hp;
    int acc;
    int damage;
    bool isBurst;
    bool isDead;
    basestats();
    QString getName();
    int getHP();
    void setHP(int);
    int getAccuracy();
    int getDamage();
    void setDead();
    bool isAlive();
};

#endif // basestats_H
