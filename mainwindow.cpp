#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loot.h"
#include "grenade.h"
#include "knife.h"
#include "inventory.h"
#include "roomlayout.h"
#include <qlabel.h>
#include <sstream>
#include "basestats.h"
#include "zombie.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startInfo->setText("Your goal is to find an exit from this \nzombie infested maze.\nYou will find weapons and medical supplies\nspread throughout the map.");
    ui->pushButton_6->setVisible(false);
    ui->scrollArea->setVisible(false);

    QPixmap pix(":images/images/bag.png");
    ui->label_6->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPixmap pix1(":images/images/chest.png");
    ui->label_9->setPixmap(pix1.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPixmap pix2(":images/images/gunBox.png");
    ui->weaponLabel->setPixmap(pix2.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->label_9->setVisible(false);
    ui->weaponButton->setVisible(false);
    ui->weaponLabel->setVisible(false);
    QPixmap pix0(":images/images/room");
    ui->label_7->setPixmap(pix0.scaled(350, 350, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    string result;

    //result = testing.addRoom("east");
    QPixmap pix3(":images/images/topdoor");
    ui->label_2->setPixmap(pix3.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPixmap pix4(":images/images/bottomdoor");
    ui->label_4->setPixmap(pix4.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPixmap pix5(":images/images/rightdoor");
    ui->label->setPixmap(pix5.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QPixmap pix6(":images/images/leftdoor");
    ui->label_3->setPixmap(pix6.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int countRoom = testing.getRoomCount();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_6_clicked() //loot button
{
    inv->addLoot(lootToAdd);
    ui->pushButton_6->setVisible(false);
    ui->label_9->setVisible(false);

}

void MainWindow::on_pushButton_7_clicked()
{
    //bag clicked
    QString output = inv->getContents();
    if(ui->scrollArea->isVisible() == true)
    {
        ui->scrollArea->setVisible(false);
    }
    else
        ui->scrollArea->setVisible(true);
    ui->label_5->setText(output);
}


void MainWindow::on_pushButton_3_clicked()
{
    //North
   makeMove("north");

}

void MainWindow::on_pushButton_2_clicked()
{
    //East
    makeMove("east");
}

void MainWindow::on_pushButton_4_clicked()
{
    //south
    makeMove("south");
}

void MainWindow::on_pushButton_clicked()
{
    //west
    makeMove("west");

}

void MainWindow::makeMove(string direction)
{
    ui->startInfo->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->weaponLabel->setVisible(false);
    ui->weaponButton->setVisible(false);
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_9->setVisible(false);//make a chest invisible if it wasnt looted
    ui->pushButton->setVisible(false); //east
    ui->pushButton_2->setVisible(false);//west
    ui->pushButton_3->setVisible(false);//north
    ui->pushButton_4->setVisible(false);//south



    QPixmap pix(":images/images/room");
    if(testing.getRoomCount() == 13) //last room of the game
    {
       generateLastRoom(direction);
    }
    else
    {
        string result;
        result = testing.addRoom(direction);
        ui->label_7->setPixmap(pix.scaled(350, 350, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        string arr[4];
        int i = 0;
        stringstream ssin(result);
        while (ssin.good() && i < 4){
            ssin >> arr[i];
            ++i;
        }
        if(arr[0] == "1")//door north
        {
            QPixmap pix(":images/images/topdoor");
            ui->label_2->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            ui->pushButton_3->setVisible(true);//north
        }
        if(arr[1] == "1")//door south
        {
            QPixmap pix(":images/images/bottomdoor");
            ui->label_4->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            ui->pushButton_4->setVisible(true);//south
        }
        if(arr[2] == "1")//door west
        {
            ui->pushButton_2->setVisible(true);//west
            QPixmap pix(":images/images/rightdoor");
            ui->label->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        }
        if(arr[3] == "1")//door west
        {
            QPixmap pix(":images/images/leftdoor");
            ui->label_3->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

            ui->pushButton->setVisible(true); //east
        }
        for(int i = 0; i < 4; i++)
            arr[i] = "";
        generateLoot();
        startFight();
    }

}

void MainWindow::generateLoot(){

    //loot
    if(testing.isNewRoom() == true)
    {
        int rand_num;
        int lowest = 1;
        int range = 1 + 3;
        rand_num = lowest + rand() % range;
        if(rand_num == 1)
        {
            //bandage
            ui->pushButton_6->setVisible(true);
            ui->label_9->setVisible(true);
            bandage newItem;
            lootToAdd = newItem;
        }
        if(rand_num == 2)
        {
            //medkit
            ui->pushButton_6->setVisible(true);
            ui->label_9->setVisible(true);
            medkit newItem;
            lootToAdd = newItem;
        }
        if(rand_num > 2)
        {
            ui->weaponButton->setVisible(true);
            ui->weaponLabel->setVisible(true);

        }
    }
}

void MainWindow::startFight()
{
    int rand_num;
    int lowest = 1;
    int range = 1 + 2;
    rand_num = lowest + rand() % range;
    if(rand_num == 2)
    {
        int chance = rand() % 100;
        if (chance < 40) {zombie *mon1 = new zombie();}
        if (chance > 40 && chance < 80) {goon *mon1 = new goon();}
        if (chance > 80) {mutant *mon1 = new mutant();}
        fightwindow fight;
        int hp = Player.getHP();
        fight.setHp(hp);
        fight.setModal(true);


        monster *enemy1 = new monster();

        enemy1 = mon1;
        fight.setInventory(inv);
        fight.fight(0,0,0,enemy1);
        fight.setWindowFlags(Qt::CustomizeWindowHint);
        fight.exec();
        Player.setHP(fight.getHp());

    }
}


void MainWindow::on_useBandage_clicked()
{
    if(inv->getContents().contains("Bandage"))
    {
        //added health
        Player.addHealth(30);
        inv->removeItem("Bandage");

    }
}


void MainWindow::on_useMedkit_clicked()
{
    if(inv->getContents().contains("Medkit"))
    {
        //added health
        Player.addHealth(150);
        inv->removeItem("Medkit");
    }
}

void MainWindow::generateLastRoom(string direction)
{
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->pushButton->setVisible(false); //east
    ui->pushButton_2->setVisible(false);//west
    ui->pushButton_3->setVisible(false);//north
    ui->pushButton_4->setVisible(false);//south
    if(direction == "north")
    {
        QPixmap pix(":images/images/bottomdoor");
        ui->label_4->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QPixmap pix1(":images/images/e_topdoor");
        ui->label_2->setPixmap(pix1.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->pushButton_3->setVisible(true);//north


    }
    else if(direction == "south")
    {
        QPixmap pix(":images/images/topdoor");
        ui->label_2->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QPixmap pix1(":images/images/e_bottomdoor");
        ui->label_4->setPixmap(pix1.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->pushButton_4->setVisible(true);//south


    }
    else if(direction == "east")
    {
        QPixmap pix(":images/images/rightdoor");
        ui->label->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QPixmap pix1(":images/images/e_leftdoor");
        ui->label_3->setPixmap(pix1.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->pushButton_2->setVisible(true); //east
    }
    else
    {

        QPixmap pix(":images/images/leftdoor");
        ui->label_3->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QPixmap pix1(":images/images/e_rightdoor");
        ui->label->setPixmap(pix1.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->pushButton->setVisible(true);//west
    }
    ui->win->setText("You Have Won the game!");

}

void MainWindow::on_weaponButton_clicked()
{
     if(inv->checkIfItemPresent("smg") == false)
        {
            smg gun;
            inv->addLoot(gun);
        }
        else if(inv->checkIfItemPresent("shotgun") == false)
        {
            shotgun gun;
            inv->addLoot(gun);
        }
        else if(inv->checkIfItemPresent("rifle") == false)
        {
            rifle gun;
            inv->addLoot(gun);
        }
        else if(inv->checkIfItemPresent("lmg") == false)
        {
            lmg gun;
            inv->addLoot(gun);
        }
        else if(inv->checkIfItemPresent("sniper") == false)
        {
            sniper gun;
            inv->addLoot(gun);
        }


    ui->weaponButton->setVisible(false);
    ui->weaponLabel->setVisible(false);
}
