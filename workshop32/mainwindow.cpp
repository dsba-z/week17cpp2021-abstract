#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
    QObject::connect(ui->addRectButton, SIGNAL(clicked()), this, SLOT(addRectangleSlot()));

    _renderArea = new RenderArea(ui->centralwidget);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(_renderArea->sizePolicy().hasHeightForWidth());
    _renderArea->setSizePolicy(sizePolicy);


    QHBoxLayout* horLayout = new QHBoxLayout(ui->centralwidget); //(centralwidget);


    horLayout->addWidget(_renderArea);
    horLayout->addWidget(ui->grpSettings);


}

void MainWindow::addRectangleSlot()
{
    _renderArea->addRectangle();
}

MainWindow::~MainWindow()
{
    delete ui;
}
