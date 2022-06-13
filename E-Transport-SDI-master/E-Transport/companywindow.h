#ifndef COMPANYWINDOW_H
#define COMPANYWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QAbstractItemView>
#include<QMessageBox>
#include <QString>
#include <QDebug>
#include <iostream>
#include <stdio.h>

#include <QFile>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>



#include <QTableWidget>
#include <QTableWidgetItem>



namespace Ui {
class companywindow;
}

class companywindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit companywindow(QWidget *parent = 0);
    ~companywindow();

    companywindow *CompanyWindowOb;
public slots:
  void on_LoadTable_clicked();


private slots:
    void on_CHome_Btn_Menu_clicked();
    void on_COrder_Btn_Menu_clicked();
    void on_CProfile_Btn_Menu_clicked();
    void on_CProfileBtn_clicked();
    void on_CEditprofilebtn_clicked();



    void on_CLogout_Btn_Menu_clicked();


    void on_pushButton_clicked();

    void on_ViewDetail_clicked();


    void on_SaveDetails_clicked();

    void on_RefreshButton_clicked();

    void on_img_clicked();

private:
    Ui::companywindow *ui;

};

#endif // COMPANYWINDOW_H
