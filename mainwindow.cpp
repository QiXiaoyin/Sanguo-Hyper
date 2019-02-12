#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qlogging.h"

#include <QByteArray>
#include <QChar>
#include <QDebug>
#include <QVector>

QString fileName;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    创建一个新的文件选择框
//    newwin = new QFileDialog;
//    newwin->show();

    //文件选择框
//    QString directory =
//            QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath());

    //文件选择框显示文件名

    //    QString directory =
    //        QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath()));
    //    QMessageBox::information(NULL, "Title", directory, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    fileName = QFileDialog::getOpenFileName(this,tr("Open File"),QDir::currentPath(), tr("*.bin"));
    if(fileName.contains("linkdata.BIN",Qt::CaseSensitive)){
        ui->comboBox->setEnabled(true);
        QMessageBox::information(NULL, "Title", "加载成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly)){
            file.seek(selectBox[index]);
            QDataStream in(&file);
            quint64 largebyte=0x08;
            quint32 mediumbyte=0x04;
            quint16 smallbyte=0x02;
                unsigned
                        __int16 singalByte;//单字节信息
//                qDebug("%s",qPrintable(chinaMonth.at(0)));

//                int b= YL_WU/largebyte;
//                for(int i=0;i<b;i++){
//                    in>>largebyte;
//                }

//                in.resetStatus();
                in.readRawData((char*)&singalByte, 2);
                file.close();

                qDebug()<<"selectBox[index] = "<<selectBox[index];
                qDebug()<<"singalByte = "<<singalByte;
      }

}
