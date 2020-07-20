#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <mysample.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void change_time(void);


private slots:
    void on_buttonMaster_valueChanged(int value);
    void on_onMaster_clicked(bool checked);
    void increaseTempo(void);

    void on_kick1Button_clicked();
    void on_kick2Button_clicked();
    void on_kick3Button_clicked();
    void on_nokickButton_clicked();
    void on_clap1Button_clicked();
    void on_clap2Button_clicked();
    void on_clap3Button_clicked();
    void on_noclapButton_clicked();
    void on_hithatButton_clicked();
    void on_nohithatButton_clicked();
    void on_shakersButton_clicked();
    void on_noshakersButton_clicked();
    void on_tomButton_clicked();
    void on_notomButton_clicked();
    void on_choirButton_clicked();
    void on_nochoirtButton_clicked();
    void on_apianoButton_clicked();
    void on_noapianoButton_clicked();
    void on_epianoButton_clicked();
    void on_noepianoButton_clicked();
    void on_aguitar1Button_clicked();
    void on_aguitar2Button_clicked();
    void on_aguitar3Button_clicked();
    void on_noaguitarButton_clicked();
    void on_sguitar1Button_clicked();
    void on_sguitar2Button_clicked();
    void on_nosguitarButton_clicked();
    void on_bass1Button_clicked();
    void on_bass2Button_clicked();
    void on_bass3Button_clicked();
    void on_bass4Button_clicked();
    void on_bass5Button_clicked();
    void on_bass6Button_clicked();

    void on_nobassButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *music;
    bool mutedMaster;
    QTimer *timer;
    mySample samples;
};
#endif // MAINWINDOW_H
