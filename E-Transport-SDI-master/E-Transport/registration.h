#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QMainWindow>
#include <QAbstractItemView>
#include<QMessageBox>

#include "ownerwindow.h"
#include "driverwindow.h"
#include "companywindow.h"

#include <QtSql>
#include <QSqlDatabase>

#define TB_NAME1 "CargoOwner"
#define TB_NAME2 "Driver"
#define TB_NAME3 "Company"


#include <iostream>

namespace Ui {
class registration;
}

class registration : public QMainWindow
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_CargoLogin_clicked();

    void on_DriverLogin_clicked();

    void on_CompanyLogin_clicked();

    void on_Register_Button_clicked();

    void on_Register_Button_2_clicked();

    void on_Register_Button_3_clicked();

    void on_pushButton_clicked();
    void on_backbtn_clicked();
    void on_backbtn2_clicked();
    void on_backbtn3_clicked();

private:
    Ui::registration *ui;
    ownerWindow *Owner;
    companywindow *Company;
    driverWindow *Driver;
    QSqlDatabase DB;


};

#endif // REGISTRATION_H
