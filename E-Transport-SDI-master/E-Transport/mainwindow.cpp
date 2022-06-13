#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->usernameLineEdit->setPlaceholderText("Please enter your Username");
    ui->passwordLineEdit->setPlaceholderText("Please enter your Password");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//page navigation to registration
void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Registration = new registration(this);
    Registration->show();
}

void MainWindow::on_checkBox_clicked()
{

}

void MainWindow::on_LoginButton_clicked()
{
    bool access = false;
    if(ui->checkBox->isChecked()){

        //connect to database
        QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");

        if(DB.open()){

            QString Username = ui->usernameLineEdit->text();
            QString Password = ui->passwordLineEdit->text();

            QSqlQuery qry(QSqlDatabase::database("MyConnect"));
            QString sql_code = "SELECT * FROM CargoOwner WHERE Username = :Username AND Password = :Password";

            qry.prepare(sql_code);

            qry.bindValue(":Username", Username);
            qry.bindValue(":Password", Password);

            qry.exec();

            if(qry.next())
            {
                QMessageBox::information(this, "Login", "Username and password correct");
//                QString GetName = "ziad";
                OwnerWindowOb = new ownerWindow(this);
                OwnerWindowOb->show();
                hide();

                access = true;
            }


            if (access == false){

                QString Username = ui->usernameLineEdit->text();
                QString Password = ui->passwordLineEdit->text();

                QSqlQuery qry(QSqlDatabase::database("MyConnect"));
                QString sql_code = "SELECT * FROM Driver WHERE Username = :Username AND Password = :Password";

                qry.prepare(sql_code);

                qry.bindValue(":Username", Username);
                qry.bindValue(":Password", Password);

                qry.exec();

                if(qry.next())
                {
                    QMessageBox::information(this, "Login", "Username and password correct");
                    DriverWindowOb = new driverWindow(this);
                    DriverWindowOb->show();
                    hide();
                    access = true;
                }

            }

            if (access == false){

                QString Username = ui->usernameLineEdit->text();
                QString Password = ui->passwordLineEdit->text();

                QSqlQuery qry(QSqlDatabase::database("MyConnect"));
                QString sql_code = "SELECT * FROM Company WHERE Username = :Username AND Password = :Password";

                qry.prepare(sql_code);

                qry.bindValue(":Username", Username);
                qry.bindValue(":Password", Password);

                qry.exec();

                if(qry.next())
                {
                    QString GetName= Username;
                    QMessageBox::information(this, "Login", "Username and password correct");
                    CompanyWindowOb = new companywindow(this);
                    CompanyWindowOb->show();
                    hide();
                    access = true;
                }
                else{
                    QMessageBox::warning(this, "Login", "Username and password incorrect");

                }
            }

        }


        else{
            QMessageBox::information(this,"Connection error","not connected to database");


        }



    }

    else {
        QMessageBox::information(this,"Error","Please agree to our terms and service");
    }













//    fstream fin;
//    fin.open("TESTCSV.csv", ios::in);
//    string inputUser, user2;

//    bool access = false;
//    bool breakTheLoop = false;
//    int count = 0, countLines = 0;
//    int itemsInLine = 15;
//    int linesInFile = 4;

//    vector <string> allUserDetails;
//    string line, item, temp;



//      while ((breakTheLoop != true) && (access != true)) {

//          allUserDetails.clear(); //clears the vector

//          getline(fin, line); //writes contents of line to String line

//          stringstream s(line); //converts string line to a string stream


//          if (countLines == linesInFile){
//              breakTheLoop = true;
//              break;
//          }

//          while (getline(s, item, ',')) { //writes the contents of s until the next comma to String item

//              allUserDetails.push_back(item); //adds item to vector

//              QString theUsernameQ = QString::fromStdString(allUserDetails[0]);
//              QString thePasswordQ = QString::fromStdString(allUserDetails[1]);

//              if (username == theUsernameQ && password == thePasswordQ && allUserDetails.size() == 15) {
//                  access = true;
//                  break;
//              }

//              count = count + 1;

//              if (count == itemsInLine){
//                  count = 0;

//                  countLines = countLines + 1;
//                  break;
//              }

//          }

//      }

//      if (access == true) {
//          QMessageBox::information(this, "Login", "Username and password correct");
//          QString theUserTypeQ = QString::fromStdString(allUserDetails[2]);
//          hide();
//          if (theUserTypeQ == "owner"){
//              OwnerWindowOb = new ownerWindow(this);
//              OwnerWindowOb->show();
//          } else if (theUserTypeQ == "driver"){
//              DriverWindowOb = new driverWindow(this);
//              DriverWindowOb->show();
//          } else if (theUserTypeQ == "company"){
//              CompanyWindowOb = new companywindow(this);
//              CompanyWindowOb->show();
//          }
//      } else {
//              QMessageBox::warning(this, "Login", "Username and password incorrect");
//          }

}
