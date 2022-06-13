#ifndef OWNERWINDOW_H
#define OWNERWINDOW_H

#include "companywindow.h"
#include <QMainWindow>
#include <iostream>
#include <QAbstractItemView>
#include<QMessageBox>
#include <QString>
#include <QDebug>

#include <QFileDialog>


#include <QtSql>
#include <QSqlDatabase>


#define TB_NAME1 "CargoOwner"
#define TB_NAME2 "Driver"
#define TB_NAME3 "Company"
#define TB_NAME4 "Orders"
#define TB_NAME5 "AcceptedOrders"
#define TB_NAME6 "Feedback"

namespace Ui {
class ownerWindow;
}

class ownerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ownerWindow(QWidget *parent = nullptr);
    ~ownerWindow();
//    void emitTheSignal();
    float amountPerParcel = 0.2;
    float lorryCharge = 1;
    int journey = 1;



signals:

public slots:

    void on_BookButton_clicked();


private slots:
    void on_Home_Btn_Menu_clicked();
    void on_Order_Btn_Menu_clicked();
    void on_Profile_Btn_Menu_clicked();
    void on_Feedback_Btn_Menu_clicked();
    void on_ProfileBtn_clicked();
    void on_Editprofilebtn_clicked();



    void on_Logout_Btn_Menu_clicked();

    void on_BookButton_2_clicked();

    void on_Submitfeedback_clicked();

    void on_ProfileBtn_2_clicked();

    void on_BookButton_3_clicked();

    void on_SaveDetails_clicked();

    void on_ProfileBtn_3_clicked();

    void on_img_clicked();

private:
    Ui::ownerWindow *ui;
    companywindow *CompanyWindowOb;
};

#endif // OWNERWINDOW_H
