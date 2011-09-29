#ifndef MAINDICE_H
#define MAINDICE_H

#include <QMainWindow>
#include <phonon/MediaObject>

namespace Ui {
    class MainDice;
}

class MainDice : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDice(QWidget *parent = 0);
    ~MainDice();

private slots:
    void on_spinBox_valueChanged(int );

    void on_pushButton_clicked();

private:
    Ui::MainDice *ui;
    Phonon::MediaObject *music;
    int dices;
};

#endif // MAINDICE_H
