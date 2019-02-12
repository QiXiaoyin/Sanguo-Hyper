#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog.h>
#include <QDir>
#include <QByteArray>
#include <QVector>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QByteArray QString16Hex(QString hexstr);

    int YL_WU       = 0x0D1D1800;
    int YL_SHU      = 0x0D1D7000;
    int JZ_GL       = 0x0D1DB800;
    int JZ_ZY       = 0x0D1DF000;
    int JT_WEI      = 0x0D1E2000;
    int JT_SHU      = 0x0D1E9000;
    int WZY_WEI     = 0x0D1E9000;
    int WZY_SHU     = 0x0D1F0000;
    int TS          = 0x0D1F8000;
    int HF_WEI      = 0x0D1FD000;
    int HF_WU       = 0x0D202000;
    const int selectBox[99] =
    {
        YL_WU ,YL_SHU ,JZ_GL ,JZ_ZY ,JT_WEI ,JT_SHU ,WZY_WEI ,WZY_SHU ,TS ,HF_WEI ,HF_WU
    };

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

public: QFileDialog *newwin;

private:
    Ui::MainWindow *ui;
    QDir currentDir;
};



#endif // MAINWINDOW_H
