#include "maindice.h"
#include "ui_maindice.h"

#include <QTime>

MainDice::MainDice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDice)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    dices=10;
    music=Phonon::createPlayer(Phonon::MusicCategory,
                               Phonon::MediaSource("dice_sound.mp3"));
}

MainDice::~MainDice()
{
    delete ui;
}

void MainDice::on_spinBox_valueChanged(int i)
{
    dices=i;
}

void MainDice::on_pushButton_clicked()
{
    music->play();
    int successes=0,ones=0,dice_result;
    for(int i=0;i<dices;i++){
        /* Random */
        dice_result=qrand()%6+1;
        if (dice_result >= 5) {
            successes++;
        } else if (dice_result == 1) {
            ones++;
        }
    }
    ui->lineEditSuccess->setText(QString::number(successes));
    ui->lineEditOnes->setText(QString::number(ones));
    if (ones >= int(double(dices)/2+0.5)) {
        if (successes==0) {
            ui->criticalGlitch->setText("Critical glitch!");
        } else {
            ui->criticalGlitch->setText("Glitch!");
        }
    } else {
        ui->criticalGlitch->setText("");
    }
}
