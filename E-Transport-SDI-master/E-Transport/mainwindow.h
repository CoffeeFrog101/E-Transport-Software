
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>
#include<QMessageBox>
#include "registration.h"
#include "ownerwindow.h"

#include <QMessageBox>
#include <QString>
#include <iostream>

#define TB_NAME1 "CargoOwner"
#define TB_NAME2 "Driver"
#define TB_NAME3 "Company"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern QString GetName;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_2_clicked();

    void on_LoginButton_clicked();

    void on_checkBox_clicked();



private:
    Ui::MainWindow *ui;
    registration *Registration;
    ownerWindow *OwnerWindowOb;
    driverWindow *DriverWindowOb;
    companywindow *CompanyWindowOb;



};
#endif // MAINWINDOW_H
