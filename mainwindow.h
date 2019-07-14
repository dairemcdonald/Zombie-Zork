#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inventory.h"
#include "roomlayout.h"
#include <qlabel.h>
#include "fightwindow.h"
#include "player.h"
#include "bandage.h"
#include "medkit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    player Player;
    inventory *inv = new inventory();
    roomLayout testing;
    int startLabel = 7;
    QList<QLabel *> labels;
    void makeMove(string direction);
    void generateLoot();
    loot lootToAdd;
    bool scrollVisible = false;
    void startFight();
    void generateLastRoom(string);

private slots:

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();



    void on_useBandage_clicked();

    void on_useMedkit_clicked();

    void on_weaponButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
