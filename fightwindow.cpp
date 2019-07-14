#include "fightwindow.h"
#include "ui_fightwindow.h"


fightwindow::fightwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightwindow)
{
    ui->setupUi(this);

    enemy1 = zom1;

    gunDmg = pistol1->getDamage();
    gunAcc = pistol1->getAccuracy();
    QString text;
    QString num;


    text = enemy1->getName();
    num = QString::number(enemy1->getHP());
    ui->label->setText(text);
    ui->label_2->setText(num);


    num = QString::number(gunAcc*0.6);
    ui->head1->setText(num);

    num = QString::number(gunAcc);
    ui->torso1->setText(num);

    num = QString::number(gunAcc * 0.8);
    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);


}

fightwindow::~fightwindow()
{
    delete ui;
}

void fightwindow::on_head1_clicked()
{
   fight(1, (gunAcc * 0.60), gunDmg, enemy1);
}

void fightwindow::on_L_arm1_clicked()
{
    fight(2, (gunAcc * 0.80), gunDmg, enemy1);
}

void fightwindow::on_R_arm1_clicked()
{
    fight(2, (gunAcc * 0.80), gunDmg, enemy1);
}

void fightwindow::on_L_leg1_clicked()
{
    fight(3, (gunAcc * 0.80), gunDmg, enemy1);
}

void fightwindow::on_R_leg1_clicked()
{

    fight(3, (gunAcc * 0.80), gunDmg, enemy1);
}

void fightwindow::on_torso1_clicked()
{
    fight(4, gunAcc, gunDmg, enemy1);
}

void fightwindow::update()
{
    QString num = QString::number(enemy1->getHP());
    ui->label_2->setText(num);


    ui->hpNumber->display(play->getHP());
}

void fightwindow::fight(int bodyPart, int acc, int dam, monster *target)
{
    if(inv->checkIfItemPresent("rifle") == false)
        ui->rifleChoice->hide();
    if(inv->checkIfItemPresent("sniper") == false)
        ui->SniperChoice->hide();
    if(inv->checkIfItemPresent("smg") == false)
        ui->smgChoice->hide();
    if(inv->checkIfItemPresent("shotgun") == false)
        ui->shotgunChoice->hide();
    if(inv->checkIfItemPresent("lmg") == false)
        ui->lmgChoice->hide();

    ui->hpNumber->display(play->getHP());
    QString damText = QString::number(dam);
    int hitCounter = 0;

    switch (bodyPart) {
    case 1:
        if (rand() % 100 < acc) {
        int headshot = dam *1.25;
        damText = QString::number(headshot);
        target->head(dam);
        ui->battleMsg->setText("hit head for " + damText + " damage!");
        update();
        }
        else {ui->battleMsg->setText("missed head!");
        update();}

         break;

    case 2:
        if (rand() % 100 < acc) {
            target->arms(dam);
            ui->battleMsg->setText("hit arms for " + damText + " damage!");
            update();
            }
            else {ui->battleMsg->setText("missed arms!");
            update();}
         break;

    case 3:  if (rand() % 100 < acc) {
            target->legs(dam);
            ui->battleMsg->setText("hit legs for " + damText + " damage!");
            update();
            }
            else {ui->battleMsg->setText("misssed legs!");
            update();}
         break;

    case 4:  if (rand() % 100 < acc) {
            target->torso(dam);
            ui->battleMsg->setText("hit torso for " + damText + " damage!");
            update();
            }
            else {ui->battleMsg->setText("misssed torso!");
            update();}
         break;

    case 5:
     if(enemy1->isAlive() == true)
     {
        if (rand() % 100 < acc)
        {
                enemy1->torso(dam);
                hitCounter++;
        }
     }


    QString hitText = QString::number(hitCounter);
    ui->battleMsg->setText("hit " + hitText + " enemies for " + damText + " damage!");
    update();
         break;

    }
    if (enemy1->getHP() < 1)
    {
        enemy1->setDead();
        close();
        killCounter++;
    }

  if (ui->widget->isEnabled()) {
    if (rand() % 100 < enemy1->getAccuracy()) {
                play->hit(enemy1->getDamage());
                damText = QString::number(enemy1->getDamage());
                ui->battleMsg->setText(ui->battleMsg->text() + "\nthe enemy hit you for " + damText + " damage!");
                update();
                }
                else {ui->battleMsg->setText(ui->battleMsg->text() +" \nenemy missed!");
                update();
    }
  }






  if (play->getHP() < 1)
  {
      exit(0);
  }
}





void fightwindow::on_pistolChoice_toggled(bool checked)
{
    if (checked){
    gunDmg = pistol1->getDamage();
    gunAcc = pistol1->getAccuracy();

    QString num = QString::number(gunAcc*0.6);
    ui->head1->setText(num);

    num = QString::number(gunAcc);
    ui->torso1->setText(num);

    num = QString::number(gunAcc * 0.8);
    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);


    burst = false;
    }
}

void fightwindow::on_rifleChoice_toggled(bool checked)
{
    if (checked){

            gunDmg = rifle1->getDamage();
            gunAcc = rifle1->getAccuracy();

            QString num = QString::number(gunAcc*0.6);
            ui->head1->setText(num);

            num = QString::number(gunAcc);
            ui->torso1->setText(num);

            num = QString::number(gunAcc * 0.8);
            ui->L_arm1->setText(num);
            ui->R_arm1->setText(num);
            ui->L_leg1->setText(num);

    burst = false;
    }
}



void fightwindow::on_SniperChoice_toggled(bool checked)
{
    if (checked){
    gunDmg = sniper1->getDamage();
    gunAcc = sniper1->getAccuracy();

    QString num = QString::number(gunAcc*0.6);
    ui->head1->setText(num);

    num = QString::number(gunAcc);
    ui->torso1->setText(num);

    num = QString::number(gunAcc * 0.8);
    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);


    burst = false;
    }
}

void fightwindow::on_smgChoice_toggled(bool checked)
{
    if (checked){
    gunDmg = smg1->getDamage();
    gunAcc = smg1->getAccuracy();

    QString num = QString::number(gunAcc);
    ui->head1->setText(num);

    ui->torso1->setText(num);

    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);


    burst = true;
    }
}

void fightwindow::on_shotgunChoice_toggled(bool checked)
{
    if (checked){
    gunDmg = shotgun1->getDamage();
    gunAcc = shotgun1->getAccuracy();

    QString num = QString::number(gunAcc);
    ui->head1->setText(num);

    ui->torso1->setText(num);

    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);


    burst = true;
    }
}

void fightwindow::on_lmgChoice_toggled(bool checked)
{
    if (checked){
    gunDmg = lmg1->getDamage();
    gunAcc = lmg1->getAccuracy();

    QString num = QString::number(gunAcc);
    ui->head1->setText(num);

    ui->torso1->setText(num);

    ui->L_arm1->setText(num);
    ui->R_arm1->setText(num);
    ui->L_leg1->setText(num);

    burst = true;
    }
}

int fightwindow::getHp()
{
    return play->getHP();
}
void fightwindow::setHp(int newHp)
{
    printf("setting new hp");
    play->setHP(newHp);
}

void fightwindow::setInventory(inventory *newInv)
{
    inv = newInv;
}
