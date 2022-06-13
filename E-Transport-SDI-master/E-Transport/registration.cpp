#include "registration.h"
#include "ui_registration.h"
#include "ownerwindow.h"

using namespace std;

registration::registration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);

    //details for cargo
           ui->nameLineEdit->setPlaceholderText("Please enter your Fullname");
           ui->emailLineEdit->setPlaceholderText("Please enter your Email");
           ui->phoneLineEdit->setPlaceholderText("Please enter your Mobile Phone number ");
           ui->addressLineEdit->setPlaceholderText("Please enter your Address");
           ui->usernameLineEdit->setPlaceholderText("Please enter your username");
           ui->passwordLineEdit->setPlaceholderText("Please enter your password");



        //details for Driver
           ui->nameLineEdit_2->setPlaceholderText("Please enter your Fullname");
           ui->emailLineEdit_2->setPlaceholderText("Please enter your Email");
           ui->nINLineEdit->setPlaceholderText("Please enter your NIN");
           ui->drivingIdLineEdit->setPlaceholderText("Please enter your Licence");
           ui->phoneLineEdit_2->setPlaceholderText("Please enter your Mobile Phone number ");
           ui->addressLineEdit_2->setPlaceholderText("Please enter your Address");
           ui->usernameLineEdit_2->setPlaceholderText("Please enter your username");
           ui->passwordLineEdit_2->setPlaceholderText("Please enter your password");
           ui->driverCertificateNoCPCLineEdit->setPlaceholderText("Please enter your CPC number");
           ui->lorryRegNoLineEdit->setPlaceholderText("Please enter your lorry Registration No");
           ui->lorryDimensionLineEdit->setPlaceholderText("Please enter your lorry dimensions (e.g 9x5m)");
           ui->lorryWeightLineEdit->setPlaceholderText("Please enter your lorry weight");



           //details for company
           ui->nameLineEdit_3->setPlaceholderText("Please enter your Fullname");
           ui->emailLineEdit_3->setPlaceholderText("Please enter your Email");
           ui->regNoLineEdit->setPlaceholderText("Please Enter Registration Number");
           ui->phoneLineEdit_3->setPlaceholderText("Please enter your Mobile Phone number ");
           ui->addressLineEdit_3->setPlaceholderText("Please enter your Address");
           ui->usernameLineEdit_3->setPlaceholderText("Please enter your username");
           ui->passwordLineEdit_3->setPlaceholderText("Please enter your password");
}



registration::~registration()
{
    delete ui;
}

//page navigation
void registration::on_CargoLogin_clicked()
{
    ui->Registration_pages->setCurrentIndex(1);
}

void registration::on_DriverLogin_clicked()
{
    ui->Registration_pages->setCurrentIndex(2);

}

void registration::on_CompanyLogin_clicked()
{
    ui->Registration_pages->setCurrentIndex(3);

}


//click register to go back to the main page
void registration::on_pushButton_clicked()
{
    this->hide();

    QWidget *parent = this->parentWidget();
    parent->show();
}
void registration::on_backbtn_clicked()
{
      ui->Registration_pages->setCurrentIndex(0);
}
void registration::on_backbtn2_clicked()
{
      ui->Registration_pages->setCurrentIndex(0);
}
void registration::on_backbtn3_clicked()
{
      ui->Registration_pages->setCurrentIndex(0);
}


//validation

void registration::on_Register_Button_clicked()//allows u to go to the owner window

{
    if(ui->Terms->isChecked()){

            //connect to database
                QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
                DB.setHostName("127.0.0.1");
                DB.setUserName("admin");
                DB.setPassword("lGArctrtpM7I");
                DB.setDatabaseName("E-TransportDB");


                if(DB.open()){

                    QString Name =ui->nameLineEdit->text();

                    QString Email =ui->emailLineEdit->text();

                    QString Phone =ui->phoneLineEdit->text();

                    QString Address =ui->addressLineEdit->text();

                    QString Username =ui->usernameLineEdit->text();

                    QString Password =ui->passwordLineEdit->text();


                    //insert data into
                    QSqlQuery Qry;
                    QString sql_code = "INSERT INTO ";
                    sql_code+= TB_NAME1;
                    sql_code += "(Name,Email,Phone,Address,Username,Password)VALUES(:Name,:Email,:Phone,:Address,:Username,:Password)";
                    Qry.prepare(sql_code);
                     Qry.bindValue(":Name",Name);
                     Qry.bindValue(":Email",Email);
                     Qry.bindValue(":Phone",Phone);
                     Qry.bindValue(":Address",Address);
                     Qry.bindValue(":Username",Username);
                     Qry.bindValue(":Password",Password);

                     if(Qry.exec()){
                         QMessageBox::information(this,"Inserted","Data as been inserted");
                         QMessageBox::information(this,"Thank you","Welcome");

                                   hide();

                                   Owner = new ownerWindow(this);

                                   Owner->show();
                     }
                     else{
                         QMessageBox::warning(this,"Failed","Data has fail to insert");
                     }
                }

                else{
                    QMessageBox::warning(this,"No connection","Not connected to the database");

                }


        }
            else{
                QMessageBox::information(this,"Error","Please agree to our terms and service");
            }


    }

    void registration::on_Register_Button_2_clicked()

    {



      if(ui->Terms_2->isChecked()){



                    //connect to database
                        QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
                        DB.setHostName("127.0.0.1");
                        DB.setUserName("admin");
                        DB.setPassword("lGArctrtpM7I");
                        DB.setDatabaseName("E-TransportDB");


                        if(DB.open()){

                            QString Name = ui->nameLineEdit_2->text();

                            QString Email = ui->emailLineEdit_2->text();

                            QString NIN = ui->nINLineEdit->text();

                            QString ID = ui->drivingIdLineEdit->text();

                            QString Phone = ui->phoneLineEdit_2->text();

                            QString Address = ui->addressLineEdit_2->text();

                            QString Username = ui->usernameLineEdit_2->text();

                            QString Password = ui->passwordLineEdit_2->text();

                            QString CPC = ui->driverCertificateNoCPCLineEdit->text();

                            QString LorryReg = ui->lorryRegNoLineEdit->text();

                            QString LorryDimension = ui->lorryDimensionLineEdit->text();

                            QString LorryWeight = ui->lorryWeightLineEdit->text();


                            if (CPC == "1000001" || CPC == "4000000" || CPC == "4000C30" || CPC == "4000C09" || CPC == "4000C10" || CPC == "2100006" || CPC == "2300000" || CPC == "5300003"){
                                if (LorryReg.size()<8){
                            //insert data into
                            QSqlQuery Qry;
                            QString sql_code = "INSERT INTO ";
                            sql_code+= TB_NAME2;
                            sql_code += "(Name,Email,NIN,ID,Phone,Address,Username,Password,CPC,LorryReg,LorryDimension,LorryWeight)VALUES(:Name,:Email,:NIN,:ID,:Phone,:Address,:Username,:Password,:CPC,:LorryReg,:LorryDimension,:LorryWeight)";
                            Qry.prepare(sql_code);
                             Qry.bindValue(":Name",Name);
                             Qry.bindValue(":Email",Email);
                             Qry.bindValue(":NIN",NIN);
                             Qry.bindValue(":ID",ID);
                             Qry.bindValue(":Phone",Phone);
                             Qry.bindValue(":Address",Address);
                             Qry.bindValue(":Username",Username);
                             Qry.bindValue(":Password",Password);
                             Qry.bindValue(":CPC",CPC);
                             Qry.bindValue(":LorryReg",LorryReg);
                             Qry.bindValue(":LorryDimension",LorryDimension);
                             Qry.bindValue(":LorryWeight",LorryWeight);

                             if(Qry.exec()){
                                 QMessageBox::information(this,"Account Created","Successfully created account");
                                 QMessageBox::information(this,"Thank you","Welcome");

                                 hide();

                                 Driver = new driverWindow(this);

                                 Driver->show();
                             }
                             else{
                                 QMessageBox::warning(this,"Failed","Incorrect data inputted");
                             }
                                } else {
                                    QMessageBox::warning(this,"Invalid REG","Does not match a valid REG Number - Must < 7");
                                }
                            } else {
                                QMessageBox::warning(this,"Invalid CPC","Does not match a valid CPC Number");
                            }
                        }
                        //else for DB FAIL
                        else{
                            QMessageBox::warning(this,"No connection","Not connected to the database");
                        }


                }  //else for terms and servce
                    else{
                        QMessageBox::information(this,"Error","Please agree to our terms and service");
                    }

}//end2

void registration::on_Register_Button_3_clicked()

{


        if(ui->Terms_3->isChecked()){



                //connect to database
                    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
                    DB.setHostName("127.0.0.1");
                    DB.setUserName("admin");
                    DB.setPassword("lGArctrtpM7I");
                    DB.setDatabaseName("E-TransportDB");


                    if(DB.open()){

                        QString Name =ui->nameLineEdit_3->text();

                        QString Email =ui->emailLineEdit_3->text();

                        QString RegNumber = ui->regNoLineEdit->text();

                        QString Phone =ui->phoneLineEdit_3->text();

                        QString Address =ui->addressLineEdit_3->text();

                        QString Username =ui->usernameLineEdit_3->text();

                        QString Password =ui->passwordLineEdit_3->text();


                        //insert data into
                        QSqlQuery Qry;
                        QString sql_code = "INSERT INTO ";
                        sql_code+= TB_NAME3;
                        sql_code += "(Name,Email,RegNumber,Phone,Address,Username,Password)VALUES(:Name,:Email,:RegNumber,:Phone,:Address,:Username,:Password)";
                        Qry.prepare(sql_code);
                         Qry.bindValue(":Name",Name);
                         Qry.bindValue(":Email",Email);
                         Qry.bindValue(":RegNumber",RegNumber);
                         Qry.bindValue(":Phone",Phone);
                         Qry.bindValue(":Address",Address);
                         Qry.bindValue(":Username",Username);
                         Qry.bindValue(":Password",Password);

                         if(Qry.exec()){
                             QMessageBox::information(this,"Inserted","Data as been inserted");
                             QMessageBox::information(this,"Thank you","Welcome");

                             hide();

                             Company = new companywindow(this);

                             Company->show();

                         }
                         else{
                             QMessageBox::warning(this,"Failed","Data has fail to insert");
                         }
                    }

                    else{
                        QMessageBox::warning(this,"No connection","Not connected to the database");
                    }


            }
                else{
                    QMessageBox::information(this,"Error","Please agree to our terms and service");
                }





}//end3
