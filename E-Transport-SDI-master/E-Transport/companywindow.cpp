#include "companywindow.h"
#include "ui_companywindow.h"
#include "ownerwindow.h"

companywindow::companywindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::companywindow)
{
    ///SetupFunction()

    ///

    ///A command that sets up the ui page and assigns prewritten “placeholders” for the lineEdit boxes when the page is loaded

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()

    ui->setupUi(this);

    ui->CUpdate_nameLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_emailLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_regNoLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_phoneLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_addressLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_usernameLineEdit->setPlaceholderText("Press 'View my details'");
    ui->CUpdate_passwordLineEdit->setPlaceholderText("Press 'View my details'");
}

companywindow::~companywindow()
{
    delete ui;
}

void companywindow::on_CHome_Btn_Menu_clicked()
{
      ui->Company_Pages->setCurrentIndex(1);
}

void companywindow::on_COrder_Btn_Menu_clicked()
{
    ///on_COrder_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the desired php SQL table will be pasted in the tableview window.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()

      ui->Company_Pages->setCurrentIndex(2);
      QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
          DB.setHostName("127.0.0.1");
          DB.setUserName("admin");
          DB.setPassword("lGArctrtpM7I");
          DB.setDatabaseName("E-TransportDB");

          if(DB.open()){

              QSqlQuery qry(QSqlDatabase::database("MyConnect"));
              QString sql_code = ("SELECT * FROM `Feedback`");
              QSqlQueryModel * modal = new QSqlQueryModel();
              qry.prepare(sql_code);
              qry.exec();
              modal->setQuery(qry);
              ui->tableView_2->setModel(modal);}

}

void companywindow::on_CProfile_Btn_Menu_clicked()
{
      ui->Company_Pages->setCurrentIndex(0);

      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Company`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int RegIndex = rec.indexOf("RegNumber");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");




            QString Name;
            QString Email;
            QString Reg;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;





      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Reg = qry.value(RegIndex).toString();
              qDebug()<<qry.value(RegIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->CUpdate_nameLineEdit->setText(Name);
      ui->CUpdate_emailLineEdit->setText(Email);
      ui->CUpdate_regNoLineEdit->setText(Reg);
      ui->CUpdate_phoneLineEdit->setText(Phone);
      ui->CUpdate_addressLineEdit->setText(Address);
      ui->CUpdate_usernameLineEdit->setText(Username);
      ui->CUpdate_passwordLineEdit->setText(Password);

      ui->CONameLabel->setText(Name);
      ui->COEmailLabel->setText(Email);
      ui->CORegLabel->setText(Reg);
      ui->COPhoneLabel->setText(Phone);
      ui->COAddressLabel->setText(Address);
      ui->COUsernameLabel->setText(Username);
      ui->COPasswordLabel->setText(Password);
}

void companywindow::on_CProfileBtn_clicked()
{
      ui->CProfilePages->setCurrentIndex(0);
      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Company`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int RegIndex = rec.indexOf("RegNumber");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");




            QString Name;
            QString Email;
            QString Reg;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;





      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Reg = qry.value(RegIndex).toString();
              qDebug()<<qry.value(RegIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->CUpdate_nameLineEdit->setText(Name);
      ui->CUpdate_emailLineEdit->setText(Email);
      ui->CUpdate_regNoLineEdit->setText(Reg);
      ui->CUpdate_phoneLineEdit->setText(Phone);
      ui->CUpdate_addressLineEdit->setText(Address);
      ui->CUpdate_usernameLineEdit->setText(Username);
      ui->CUpdate_passwordLineEdit->setText(Password);

      ui->CONameLabel->setText(Name);
      ui->COEmailLabel->setText(Email);
      ui->CORegLabel->setText(Reg);
      ui->COPhoneLabel->setText(Phone);
      ui->COAddressLabel->setText(Address);
      ui->COUsernameLabel->setText(Username);
      ui->COPasswordLabel->setText(Password);
}

void companywindow::on_CEditprofilebtn_clicked()
{
    ///on_CEditprofilebtn_clicked()

    ///

    ///A function codes a button so that when clicked, the profile information will be pasted inside the profile window.

    ///@param nameIndex is a parameter type integer used to retrieve the table index value of Name from the phptable. (emailIndex, phoneIndex, addressIndex, usernameIndex, passwordIndex carry out the same actions for their specific columns.)

    ///@param Name is a parameter type String that stores the value of Name retrieved from the phptable. (Email, phone, address, username, password carry out the same actions for their specific columns.)

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()



      ui->CProfilePages->setCurrentIndex(1);
      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Company`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int RegIndex = rec.indexOf("RegNumber");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");




            QString Name;
            QString Email;
            QString Reg;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;





      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Reg = qry.value(RegIndex).toString();
              qDebug()<<qry.value(RegIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->CUpdate_nameLineEdit->setText(Name);
      ui->CUpdate_emailLineEdit->setText(Email);
      ui->CUpdate_regNoLineEdit->setText(Reg);
      ui->CUpdate_phoneLineEdit->setText(Phone);
      ui->CUpdate_addressLineEdit->setText(Address);
      ui->CUpdate_usernameLineEdit->setText(Username);
      ui->CUpdate_passwordLineEdit->setText(Password);

      ui->CONameLabel->setText(Name);
      ui->COEmailLabel->setText(Email);
      ui->CORegLabel->setText(Reg);
      ui->COPhoneLabel->setText(Phone);
      ui->COAddressLabel->setText(Address);
      ui->COUsernameLabel->setText(Username);
      ui->COPasswordLabel->setText(Password);
}

void companywindow::on_CLogout_Btn_Menu_clicked()
{
    ///on_CLogout_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the user can log out of the session.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()

    this->hide();

    QWidget *parent = this->parentWidget();
    parent->show();
}


void companywindow::on_LoadTable_clicked()
{
    ///on_LoadTable_clicked()

    ///

    ///A function codes a button so that when clicked, the desired php SQL table will be pasted in the tableview window.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()



    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");

        if(DB.open()){

            QSqlQuery qry(QSqlDatabase::database("MyConnect"));
            QString sql_code = ("SELECT * FROM `Orders`");
            QSqlQueryModel * modal = new QSqlQueryModel();
            qry.prepare(sql_code);
            qry.exec();
            modal->setQuery(qry);
            ui->tableView->setModel(modal);

            QSqlQuery qry2(QSqlDatabase::database("MyConnect"));
            QString sql_code2 = ("SELECT * FROM `Orders`");
            qry2.prepare(sql_code2);
            QString orderID;
            qry2.exec();
            QSqlRecord rec = qry2.record();
            int orderIDindex = rec.indexOf("OrderID");

            while(qry2.next()){

                    orderID = qry2.value(orderIDindex).toString();
                    qDebug()<<qry2.value(orderIDindex).toString();



                    ui->selectOrderIDComboBox->addItem(orderID);


            }

        } else{
            QMessageBox::information(this,"Connection error","not connected to database");
        }


}

void companywindow::on_pushButton_clicked()
{
    ///on_pushButton_clicked()

    ///

    ///A function codes a button so that when clicked, the commission will be printed to the user.

    ///@param Invoice amount is a parameter type QString that stores the name of the user.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()



    QString OrderID = ui->selectOrderIDComboBox->currentText();
    int Cost;
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");


        if(DB.open()){
            QSqlQuery qry2(QSqlDatabase::database("MyConnect"));
            QString sql_code2 = ("SELECT Cost FROM `Orders` WHERE OrderID = '"+OrderID+"'");
            qry2.prepare(sql_code2);
            QString orderID;
            qry2.exec();
            QSqlRecord rec = qry2.record();
            int Costindex = rec.indexOf("Cost");

            while(qry2.next()){

                Cost = qry2.value(Costindex).toInt();
                qDebug()<<qry2.value(Costindex).toString();



             int Commission = Cost*0.3;//30%
         QString CommissionQ = QString::number(Commission);
         QMessageBox::information(this,"Order Sent","Order Sent to available drivers");
            QMessageBox::information(this," - COMPANY COMMISSION - ", ""
                                                             "----------------------- \n"
                                                             "    Total commission fee = £"+CommissionQ+"\n"
                                                                                                           "-----------------------");


            }
        }
}

void companywindow::on_ViewDetail_clicked()
{

    ///on_ViewDetail_clicked()

    ///

    ///A function codes a button so that when clicked, the profile information will be pasted inside the profile window.

    ///@param nameIndex is a parameter type integer used to retrieve the table index value of Name from the phptable. (emailIndex, regIndex, phoneIndex, addressIndex, usernameIndex, passwordIndex carry out the same actions for their specific columns.)

    ///@param Name is a parameter type String that stores the value of Name retrieved from the phptable. (Email, phone, Reg, address, username, password carry out the same actions for their specific columns.)

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()

    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `Company`");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int nameIndex = rec.indexOf("Name");
     int emailIndex = rec.indexOf("Email");
     int RegIndex = rec.indexOf("RegNumber");
     int phoneIndex = rec.indexOf("Phone");
     int addressIndex = rec.indexOf("Address");
     int usernameIndex = rec.indexOf("Username");
     int passwordIndex = rec.indexOf("Password");

          QString Name;
          QString Email;
          QString Reg;
          QString Phone;
          QString Address;
          QString Username;
          QString Password;

    while(qry.next()){

            Name = qry.value(nameIndex).toString();
            qDebug()<<qry.value(nameIndex).toString();

            Email = qry.value(emailIndex).toString();
            qDebug()<<qry.value(emailIndex).toString();

            Reg = qry.value(RegIndex).toString();
            qDebug()<<qry.value(RegIndex).toString();

            Phone = qry.value(phoneIndex).toString();
            qDebug()<<qry.value(phoneIndex).toString();

            Address = qry.value(addressIndex).toString();
            qDebug()<<qry.value(addressIndex).toString();

            Username = qry.value(usernameIndex).toString();
            qDebug()<<qry.value(usernameIndex).toString();

            Password = qry.value(passwordIndex).toString();
            qDebug()<<qry.value(passwordIndex).toString();

    }

    ui->CUpdate_nameLineEdit->setText(Name);
    ui->CUpdate_emailLineEdit->setText(Email);
    ui->CUpdate_regNoLineEdit->setText(Reg);
    ui->CUpdate_phoneLineEdit->setText(Phone);
    ui->CUpdate_addressLineEdit->setText(Address);
    ui->CUpdate_usernameLineEdit->setText(Username);
    ui->CUpdate_passwordLineEdit->setText(Password);

    ui->CONameLabel->setText(Name);
    ui->COEmailLabel->setText(Email);
    ui->CORegLabel->setText(Reg);
    ui->COPhoneLabel->setText(Phone);
    ui->COAddressLabel->setText(Address);
    ui->COUsernameLabel->setText(Username);
    ui->COPasswordLabel->setText(Password);


}


void companywindow::on_SaveDetails_clicked()
{
    ///on_SaveDetails_clicked()

    ///

    ///A function codes a button so that when clicked, the changes values in the profile page will be updated in the database.

    ///@param name is a parameter type QString that stores the name of the user.

    ///@param Email is a parameter type QString that stores the Email of the user.

    ///@param Reg is a parameter type QString that stores the Reg number of the user.

    ///@param Phone is a parameter type QString that stores the Phone of the user.

    ///@param Address is a parameter type QString that stores the Address of the user.

    ///@param Username is a parameter type QString that stores the Username of the user.

    ///@param Password is a parameter type QString that stores the Password of the user.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()

    QString originalName = ui->CONameLabel->text();

    QString Name = ui->CUpdate_nameLineEdit->text();
    QString Email = ui->CUpdate_emailLineEdit->text();
    QString RegNumber = ui->CUpdate_regNoLineEdit->text();
    QString Phone = ui->CUpdate_phoneLineEdit->text();
    QString Address = ui->CUpdate_addressLineEdit->text();
    QString Username = ui->CUpdate_usernameLineEdit->text();
    QString Password = ui->CUpdate_passwordLineEdit->text();

    //connect to database
        QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");


        if(DB.open()){

            QSqlQuery DelQry;
            QString sql_code2 = "DELETE FROM `Company` WHERE Name = '"+originalName+"'";
            DelQry.prepare(sql_code2);
            DelQry.exec();

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
                 QMessageBox::information(this,"Details Saved","Your details have been updated");

             }
             else{
                 QMessageBox::warning(this,"Failed","Data has fail to insert");
             }
        }

        else{
            QMessageBox::warning(this,"No connection","Not connected to the database");
        }
}

void companywindow::on_RefreshButton_clicked()
{
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");

        if(DB.open()){

            QSqlQuery qry(QSqlDatabase::database("MyConnect"));
            QString sql_code = ("SELECT * FROM `Feedback`");
            QSqlQueryModel * modal = new QSqlQueryModel();
            qry.prepare(sql_code);
            qry.exec();
            modal->setQuery(qry);
            ui->tableView_2->setModel(modal);}
}

void companywindow::on_img_clicked()
{
    ///on_img_clicked()

    ///

    ///A function codes a button so that when clicked, a file window window is opened where a user can choose a profile picture.

    ///@param name is a parameter type QString that stores the file name of the image.

    ///@param name is a parameter type bool that stores the a value determining whether the picture is valid to place in the profile image window.

    ///@returns void

    ///@see SetupFunction() on_COrder_Btn_Menu_clicked() on_Profile_Btn_Menu_clicked() on_CLogout_Btn_Menu_clicked() on_LoadTable_clicked() on_pushButton_clicked() on_ViewDetail_clicked() on_SaveDetails_clicked() on_img_clicked()



    QString FileName = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));

    if(QString::compare(FileName,QString())!=0)
    {
        QImage img;
        bool valid = img.load(FileName);
        if(valid){
            img = img.scaledToWidth(ui->ProfileLogo->width(), Qt::SmoothTransformation);
            ui->ProfileLogo->setPixmap(QPixmap::fromImage(img));
        }
        else
        {
            //error handeling
        }
    }
}
