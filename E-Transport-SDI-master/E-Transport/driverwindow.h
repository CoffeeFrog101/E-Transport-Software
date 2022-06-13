#ifndef DRIVERWINDOW_H
#define DRIVERWINDOW_H

#define TB_NAME1 "CargoOwner"
#define TB_NAME2 "Driver"
#define TB_NAME3 "Company"
#define TB_NAME4 "Orders"
#define TB_NAME5 "AcceptedOrders"
#define TB_NAME6 "Feedback"

#include <QMainWindow>

#include <QtSql>
#include <QSqlDatabase>
#include "ownerwindow.h"
#include "companywindow.h"
#include <QDebug>
#include <iostream>

namespace Ui {
class driverWindow;
}

class driverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit driverWindow(QWidget *parent = 0);
    ~driverWindow();

public slots:
    void on_Loadtable_clicked();

private slots:
    void on_Home_Btn_Menu_2_clicked();
    void on_Order_Btn_Menu_2_clicked();
    void on_Profile_Btn_Menu_2_clicked();
    void on_Feedback_Btn_Menu_2_clicked();
    void on_ProfileBtn_2_clicked();
    void on_Editprofilebtn_2_clicked();

    void on_Logout_Btn_Menu_clicked();


    void on_pushButton_clicked();

    void on_updateStatusButton_clicked();

    void on_Submitfeedback_2_clicked();

    void on_ViewDetail_clicked();

    void on_SaveDetails_2_clicked();

    void on_img_clicked();

private:
    Ui::driverWindow *ui;
};

#endif // DRIVERWINDOW_H
