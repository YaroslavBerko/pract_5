#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::rbChecked()
{
    stop = false;
    while(!stop){
            timer.restart();
            for(;timer.elapsed() < 1000;)
            {
            }
            if (ui->green->isChecked())
                ui->red->setChecked(true);
            else
                if (ui->red->isChecked())
                    ui->orange->setChecked(true);
                else
                    ui->green->setChecked(true);
            setUpdatesEnabled(true);
            repaint();
            setUpdatesEnabled(false);
    }
}

void MainWindow::bStopPresed()
{
    stop = true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stop = false;
    timer.start();
    QObject::connect(ui->bStart, SIGNAL(clicked()), this, SLOT(rbChecked()));
    QObject::connect(ui->bStop, SIGNAL(clicked()), this, SLOT(bStopPresed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
