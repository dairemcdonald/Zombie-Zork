#ifndef FIGHTWINDOW_H
#define FIGHTWINDOW_H

#include <QDialog>
#include "zombie.h"
#include "player.h"
#include "pistol.h"
#include "rifle.h"
#include "sniper.h"
#include "smg.h"
#include "shotgun.h"
#include "lmg.h"
#include "inventory.h"

namespace Ui {
class fightwindow;
}

class fightwindow : public QDialog
{
	Q_OBJECT

public:
	explicit fightwindow(QWidget *parent = 0);
	~fightwindow();
	player *play = new player();
	inventory *inv = new inventory();
	pistol *pistol1 = new pistol();
	rifle *rifle1 = new rifle();
	sniper *sniper1 = new sniper();
	smg *smg1 = new smg();
	shotgun *shotgun1 = new shotgun();
	lmg *lmg1 = new lmg();

	int killCounter = 0;
	monster *enemy1 = enemy1;

	int gunDmg;
	int gunAcc;
	bool burst = false;

	int getHp();
	void setHp(int);
	void setInventory(inventory *newInv);
	void fight(int, int, int, monster *);

private slots:
	void on_head1_clicked();

	void on_L_arm1_clicked();

	void on_R_arm1_clicked();

	void on_R_leg1_clicked();

	void on_torso1_clicked();

	void on_L_leg1_clicked();

	void on_pistolChoice_toggled(bool checked);

	void on_rifleChoice_toggled(bool checked);

	void update();



	//void kill(monster *);






	void on_SniperChoice_toggled(bool checked);

	void on_smgChoice_toggled(bool checked);

	void on_shotgunChoice_toggled(bool checked);

	void on_lmgChoice_toggled(bool checked);

private:
	Ui::fightwindow *ui;
};

#endif // FIGHTWINDOW_H
