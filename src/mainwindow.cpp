#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->capacity,SIGNAL(returnPressed()) ,this,SLOT(capacidad_tanque()));
    connect(ui->set_timer,SIGNAL(returnPressed()),this,SLOT(timer_slot()));

    QString setter_time;
    setter_time = ui->set_timer->text();

    time_s = setter_time.toInt();
    if(ui->set_timer->text().isEmpty() == true)
    {
        time_s = 1000;
    }

    timer.start(time_s);
    connect(&timer,SIGNAL(timeout()),this,SLOT(simulation()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::simulation()
{
    QString f_in, f_out;
    float fl_in,fl_out;

    f_in  = ui->flow_in ->text();
    f_out = ui->flow_out->text();

    fl_in  = f_in.toFloat();
    fl_out = f_out.toFloat();

    float val_in  = ui->valvula_in ->value();
    float val_out = ui->valvula_out->value();

    float real_flow_in  = fl_in  * (val_in /100) *(time_s/1000);
    float real_flow_out = fl_out * (val_out/100) *(time_s/1000);

    float litros_actuales = ui->tank->value();
    float litros_entrada = litros_actuales + (real_flow_in - real_flow_out);
    ui->tank->setValue(litros_entrada);
}
void MainWindow::capacidad_tanque()
{
    QString value;
    value = ui->capacity->text();
    capacidad = value.toInt();
    ui->tank->setMaximum(capacidad);
}

void MainWindow::timer_slot()
{
    QString setter_time;
    setter_time = ui->set_timer->text();
    if(ui->set_timer->text().isEmpty() == true)
    {
        time_s = 1000;
    }
    time_s = setter_time.toInt();

}

