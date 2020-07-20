#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QDebug>
#include <QtConcurrent/QtConcurrentRun>
#include <QTimer>


void MainWindow::on_kick1Button_clicked()
{
    ui->kick1Button->setDefault(true);
    ui->kick2Button->setDefault(false);
    ui->kick3Button->setDefault(false);
    samples.wantoplay("kick1");
}

void MainWindow::on_kick2Button_clicked()
{
    ui->kick1Button->setDefault(false);
    ui->kick2Button->setDefault(true);
    ui->kick3Button->setDefault(false);
    samples.wantoplay("kick2");
}

void MainWindow::on_kick3Button_clicked()
{
    ui->kick1Button->setDefault(false);
    ui->kick2Button->setDefault(false);
    ui->kick3Button->setDefault(true);
    samples.wantoplay("kick3");
}

void MainWindow::on_nokickButton_clicked()
{
    ui->kick1Button->setDefault(false);
    ui->kick2Button->setDefault(false);
    ui->kick3Button->setDefault(false);
    samples.wantostop("kick");
}

void MainWindow::on_clap1Button_clicked()
{
    samples.wantoplay("clap1");
}

void MainWindow::on_clap2Button_clicked()
{
    samples.wantoplay("clap2");
}

void MainWindow::on_clap3Button_clicked()
{
    samples.wantoplay("clap3");
}

void MainWindow::on_noclapButton_clicked()
{
    samples.wantostop("clap");
}

void MainWindow::on_hithatButton_clicked()
{
    samples.wantoplay("hithat");
}

void MainWindow::on_nohithatButton_clicked()
{
    samples.wantostop("hithat");
}

void MainWindow::on_shakersButton_clicked()
{
    samples.wantoplay("shakers");
}

void MainWindow::on_noshakersButton_clicked()
{
    samples.wantostop("shakers");
}

void MainWindow::on_tomButton_clicked()
{
    samples.wantoplay("tom");
}

void MainWindow::on_notomButton_clicked()
{
    samples.wantostop("tom");
}

void MainWindow::on_choirButton_clicked()
{
    samples.wantoplay("choir");
}

void MainWindow::on_nochoirtButton_clicked()
{
    samples.wantostop("choir");
}

void MainWindow::on_apianoButton_clicked()
{
    samples.wantoplay("apiano");
}

void MainWindow::on_noapianoButton_clicked()
{
    samples.wantostop("apiano");
}

void MainWindow::on_epianoButton_clicked()
{
    samples.wantoplay("epiano");
}

void MainWindow::on_noepianoButton_clicked()
{
    samples.wantostop("epiano");
}

void MainWindow::on_aguitar1Button_clicked()
{
    samples.wantoplay("aguitar1");
}

void MainWindow::on_aguitar2Button_clicked()
{
    samples.wantoplay("aguitar2");
}

void MainWindow::on_aguitar3Button_clicked()
{
    samples.wantoplay("aguitar3");
}

void MainWindow::on_noaguitarButton_clicked()
{
    samples.wantostop("aguitar");
}

void MainWindow::on_sguitar1Button_clicked()
{
    samples.wantoplay("sguitar1");
}

void MainWindow::on_sguitar2Button_clicked()
{
    samples.wantoplay("sguitar2");
}

void MainWindow::on_nosguitarButton_clicked()
{
    samples.wantostop("sguitar");
}

void MainWindow::on_bass1Button_clicked()
{
    samples.wantoplay("bass1");
}

void MainWindow::on_bass2Button_clicked()
{
    samples.wantoplay("bass2");
}

void MainWindow::on_bass3Button_clicked()
{
    samples.wantoplay("bass3");
}

void MainWindow::on_bass4Button_clicked()
{
    samples.wantoplay("bass4");
}

void MainWindow::on_bass5Button_clicked()
{
    samples.wantoplay("bass5");
}

void MainWindow::on_bass6Button_clicked()
{
    samples.wantoplay("bass6");
}

void MainWindow::on_nobassButton_clicked()
{
    samples.wantostop("bass");
}
