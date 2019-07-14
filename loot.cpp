#include "loot.h"
loot::loot()
{

}
QString loot::getName()
{
    //return QString::fromStdString("error");
    return QString::fromStdString(itemname);
}
QString loot::getDescription()
{
    //return QString::fromStdString("error");
    return QString::fromStdString(description);
}

