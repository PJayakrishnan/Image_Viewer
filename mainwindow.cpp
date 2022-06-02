#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnImageBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Choose Image","C:\\","Images (*.png *.xpm *.jpg)");
    QPixmap imageMap(filePath);

    ui->lblImageBox->setPixmap(imageMap);

    QFileInfo file(filePath);
    ui->lblDetailsfileName->setText(file.fileName());

    QString dimension = QString::number(imageMap.width()) +" X " + QString::number(imageMap.height());
    ui->lblDetailsDimensions->setText(dimension);
}

