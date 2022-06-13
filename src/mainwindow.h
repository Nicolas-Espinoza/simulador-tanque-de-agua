#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

//mis modificaciones

public slots:
    void simulation();
    void capacidad_tanque();
    void timer_slot();


private:
    QTimer timer;
    int time_s;
    int capacidad;
};

#endif // MAINWINDOW_H
