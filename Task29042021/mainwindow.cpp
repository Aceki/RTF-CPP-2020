#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "dot_widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DotWidget* rdw = new DotWidget(this);

    ui->verticalLayout->addWidget(rdw);
}

MainWindow::~MainWindow()
{
    delete ui;
}

