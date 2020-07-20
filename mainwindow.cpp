#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mysample.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QDebug>
#include <QtConcurrent/QtConcurrentRun>
#include <QTimer>

int mBPM(int BPM)
{
    float value = 0;

    value = 60000 / BPM;
    return value;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    music = new QMediaPlayer();
    timer = new QTimer();

    music->setMedia(QUrl("qrc:/music/test.mp3"));
    music->play();
    music->setVolume(0);
    mutedMaster = false;
    samples.play();

    timer->setInterval(10);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(increaseTempo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::increaseTempo()
{
    int tmp{(int)music->position() / mBPM(116) % 8};
    float tempo{(float)(60000/ 116)};
    int frame{(int)music->position() * 1000 / (int)(tempo)};

    qDebug() << frame % 8000;
    ui->Tempo->setValue(tmp + 1);
    if (frame % 8000 >= 0 && frame % 8000 <= 20)
        samples.play();
    if (music->position() == music->duration())
        music->setPosition(0);

    ui->measureTime->display((tmp / 4) + 1);
    ui->measureTempo->display((tmp % 4) + 1);
    timer->start(10);
}

void MainWindow::on_buttonMaster_valueChanged(int value)
{
    ui->volumeMaster->display(value);
    music->setVolume(value);
}

void MainWindow::on_onMaster_clicked(bool checked)
{
    if (mutedMaster == true) {
        mutedMaster = false;
        ui->onMaster->setText("ON");
    } else {
        mutedMaster = true;
        ui->onMaster->setText("OFF");
    }
    music->setMuted(mutedMaster);
    (void)checked;
}
