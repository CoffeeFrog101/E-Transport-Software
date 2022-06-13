#include "ownerwindow.h"
#include "ui_ownerwindow.h"
#include "companywindow.h"
#include "mainwindow.h"




using namespace std;

ownerWindow::ownerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ownerWindow)
{
    ///SetupFunction()

    ///

    ///A command that sets up the ui page and assigns prewritten “placeholders” for the lineEdit boxes when the page is loaded

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

    ui->setupUi(this);
    ui->OUpdate_nameLineEdit->setPlaceholderText("Press 'View my details'");
    ui->OUpdate_emailLineEdit->setPlaceholderText("Press 'View my details'");
    ui->OUpdate_phoneLineEdit->setPlaceholderText("Press 'View my details'");
    ui->OUpdate_addressLineEdit->setPlaceholderText("Press 'View my details'");
    ui->OUpdate_usernameLineEdit_2->setPlaceholderText("Press 'View my details'");
    ui->OUpdate_passwordLineEdit->setPlaceholderText("Press 'View my details'");





}

ownerWindow::~ownerWindow()
{
    delete ui;
}

//Order_Btn_Menu
void ownerWindow::on_Home_Btn_Menu_clicked()
{
      ui->Owner_Pages->setCurrentIndex(0);
}

void ownerWindow::on_Order_Btn_Menu_clicked()
{

    ///on_Order_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the desired php SQL table will be pasted in the tableview window.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()
    ///
      ui->Owner_Pages->setCurrentIndex(1);
      QSqlQuery qry2(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Orders`");
      QSqlQueryModel * modal = new QSqlQueryModel();
      qry2.prepare(sql_code2);
      qry2.exec();
      modal->setQuery(qry2);
      ui->OrderHistoryView->setModel(modal);

}

void ownerWindow::on_Profile_Btn_Menu_clicked()
{
    ///on_Profile_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the profile information will be pasted inside the profile window.

    ///@param nameIndex is a parameter type integer used to retrieve the table index value of Name from the phptable. (emailIndex, phoneIndex, addressIndex, usernameIndex, passwordIndex carry out the same actions for their specific columns.)

    ///@param Name is a parameter type String that stores the value of Name retrieved from the phptable. (Email, phone, address, username, password carry out the same actions for their specific columns.)

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

      ui->Owner_Pages->setCurrentIndex(2);
      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `CargoOwner`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");

            QString Name;
            QString Email;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;



      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->OUpdate_nameLineEdit->setText(Name);
      ui->OUpdate_emailLineEdit->setText(Email);
      ui->OUpdate_phoneLineEdit->setText(Phone);
      ui->OUpdate_addressLineEdit->setText(Address);
      ui->OUpdate_usernameLineEdit_2->setText(Username);
      ui->OUpdate_passwordLineEdit->setText(Password);

      ui->OWNameLabel->setText(Name);
      ui->OWEmailLabel->setText(Email);
      ui->OWPhoneLabel->setText(Phone);
      ui->OWaddressLabel->setText(Address);
      ui->OWusernameLabel->setText(Username);
      ui->OWpasswordLabel->setText(Password);
}

void ownerWindow::on_Feedback_Btn_Menu_clicked()
{
      ui->Owner_Pages->setCurrentIndex(3);
}

void ownerWindow::on_ProfileBtn_clicked()
{


      ui->ProfilePages->setCurrentIndex(0);
      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `CargoOwner`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");

            QString Name;
            QString Email;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;



      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->OUpdate_nameLineEdit->setText(Name);
      ui->OUpdate_emailLineEdit->setText(Email);
      ui->OUpdate_phoneLineEdit->setText(Phone);
      ui->OUpdate_addressLineEdit->setText(Address);
      ui->OUpdate_usernameLineEdit_2->setText(Username);
      ui->OUpdate_passwordLineEdit->setText(Password);

      ui->OWNameLabel->setText(Name);
      ui->OWEmailLabel->setText(Email);
      ui->OWPhoneLabel->setText(Phone);
      ui->OWaddressLabel->setText(Address);
      ui->OWusernameLabel->setText(Username);
      ui->OWpasswordLabel->setText(Password);
}

void ownerWindow::on_Editprofilebtn_clicked()
{
      ui->ProfilePages->setCurrentIndex(1);

      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `CargoOwner`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");

            QString Name;
            QString Email;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;



      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();

              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

      }

      ui->OUpdate_nameLineEdit->setText(Name);
      ui->OUpdate_emailLineEdit->setText(Email);
      ui->OUpdate_phoneLineEdit->setText(Phone);
      ui->OUpdate_addressLineEdit->setText(Address);
      ui->OUpdate_usernameLineEdit_2->setText(Username);
      ui->OUpdate_passwordLineEdit->setText(Password);

      ui->OWNameLabel->setText(Name);
      ui->OWEmailLabel->setText(Email);
      ui->OWPhoneLabel->setText(Phone);
      ui->OWaddressLabel->setText(Address);
      ui->OWusernameLabel->setText(Username);
      ui->OWpasswordLabel->setText(Password);
}

void ownerWindow::on_BookButton_clicked()
{
    ///on_BookButton_clicked()

    ///

    ///A function codes a button so that when clicked, the order details will be calculated and stored using the user’s inputted values.

    ///@param journey is a parameter type int that stores the journey charge depending on the source and destination.

    ///@param source is a parameter type QString that stores the journey source value.

    ///@param destination is a parameter type QString that stores the journey destination value.

    ///@param lorrySize is a parameter type QString that stores the lorry size value.

    ///@param seed is a parameter type unsigned that stores the value of time, used to create a random number later.

    ///@param randNo is a parameter type int that stores the a random number between 99 and 10000.

    ///@param Status is a parameter type int that stores the status of an order.

    ///@param noOfParcelsQ is a parameter type QString that stores the number of parcels for that order.

    ///@param lengthQ is a parameter type QString that stores the length of the cargo.

    ///@param widthQ is a parameter type QString that stores the width of the cargo.

    ///@param weightQ is a parameter type QString that stores the weight of the cargo.

    ///@param Cost is a parameter type int that stores the cost of the order.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

QString source = ui->sourceComboBox->currentText();
QString destination = ui->destComboBox->currentText();
QString lorrySize = ui->sizeComboBox->currentText();
int journey = 1;

unsigned seed = time(0);
srand(seed);

int randNo = rand()%4500+5000;
QString randNoQ = QString::number(randNo);
QString OrderID = ("ORD"+randNoQ);

int randNo2 = rand()%4501+5000;
QString randNoQ2 = QString::number(randNo2);
QString TrackingID = ("TRA"+randNoQ2);

QString Status = "pending";

if((source=="London" && destination == "Manchester")||((source=="Manchester" && destination == "London"))){
    journey = 100;
    cout<<"journey = "<<journey<<endl;
}
if((source=="Manchester" && destination == "Birmingham")||((source=="Birmingham" && destination == "Manchester"))){

    journey = 50;
    cout<<"journey = "<<journey<<endl;
}
if((source=="London" && destination == "Birmingham")||((source=="Birmingham" && destination == "London"))){

    journey = 60;
    cout<<"journey = "<<journey<<endl;
}
if(source == destination)
{
    QMessageBox::warning(this,"Failed","Source and Destination are the same");

}
if (lorrySize == "small"){
    lorryCharge = 1;
} else if (lorrySize == "medium"){
    lorryCharge = 1.5;
} else if (lorrySize == "large"){
    lorryCharge = 2;
}
QString noOfParcelsQ = ui->ParcelsInput->text();
QString lengthQ = ui->LengthInput->text();
QString widthQ = ui->WidthInput->text();
QString weightQ = ui->WeightInput->text();
QString Source = ui->sourceComboBox->currentText();
QString Destination = ui->destComboBox->currentText();
QString Type = ui->sizeComboBox->currentText();



int noOfParcelsInt = noOfParcelsQ.toInt();
int Length = lengthQ.toInt();
int Width = widthQ.toInt();
int Weight = weightQ.toInt();


float Cost = ((noOfParcelsInt*amountPerParcel*lorryCharge)+journey);
QString costQString = QString::number(Cost);


if(widthQ==""||weightQ==""||lengthQ==""||noOfParcelsQ==""||source == destination)
{



    QMessageBox::warning(this,"Failed","Please fill out the form correctly");

}
else{
//connect to database
QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
DB.setHostName("127.0.0.1");
DB.setUserName("admin");
DB.setPassword("lGArctrtpM7I");
DB.setDatabaseName("E-TransportDB");
    try {



        if(DB.open()){


            //insert data into
            QSqlQuery Qry;
            QString sql_code = "INSERT INTO ";
            sql_code+= TB_NAME4;
            sql_code += "(OrderID,Cost,TrackingID,Status,Source,Destination,Type,Weight,Width,Length)VALUES(:OrderID,:Cost,:TrackingID,:Status,:Source,:Destination,:Type,:Weight,:Width,:Length)";
            Qry.prepare(sql_code);
             Qry.bindValue(":OrderID",OrderID);
             Qry.bindValue(":Cost",Cost);
             Qry.bindValue(":TrackingID",TrackingID);
             Qry.bindValue(":Status",Status);
             Qry.bindValue(":Source",Source);
             Qry.bindValue(":Destination",Destination);
             Qry.bindValue(":Type",Type);
             Qry.bindValue(":Weight",Weight);
             Qry.bindValue(":Width",Width);
             Qry.bindValue(":Length",Length);

             if(Qry.exec()){
                 QMessageBox::information(this,"Success!!!","Your Order has been placed sucessfully");

             }
             else{
                 QMessageBox::warning(this,"Failed","Your order request have been denied");
             }
        }

        else{
            QMessageBox::critical(this,"No connection","Not connected to the database");

        }

        QSqlQuery qry2(QSqlDatabase::database("MyConnect"));
        QString sql_code2 = ("SELECT * FROM `Orders`");
        QSqlQueryModel * modal = new QSqlQueryModel();
        qry2.prepare(sql_code2);
        qry2.exec();
        modal->setQuery(qry2);
        ui->OrderHistoryView->setModel(modal);
        ui->InvoiceAmount->setText(costQString);

}
    catch (const std::exception &e) {
        QMessageBox::warning(this,"Error",e.what());

        }
}

}

void ownerWindow::on_Logout_Btn_Menu_clicked()
{
    ///on_Logout_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the user can log out of the session.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

    this->hide();

    QWidget *parent = this->parentWidget();
    parent->show();
}


void ownerWindow::on_BookButton_2_clicked()
{

QString source = ui->sourceComboBox->currentText();
QString destination = ui->destComboBox->currentText();
QString lorrySize = ui->sizeComboBox->currentText();

    if((source=="London" && destination == "Manchester")||((source=="Manchester" && destination == "London"))){
        journey = 100;
        cout<<"journey = "<<journey<<endl;
    }
    if((source=="Manchester" && destination == "Birmingham")||((source=="Birmingham" && destination == "Manchester"))){

        journey = 50;
        cout<<"journey = "<<journey<<endl;
    }
    if((source=="London" && destination == "Birmingham")||((source=="Birmingham" && destination == "London"))){

        journey = 60;
        cout<<"journey = "<<journey<<endl;
    }
    if((source=="Nottingham" && destination == "Birmingham")||((source=="Birmingham" && destination == "Nottingham"))){

        journey = 20;
        cout<<"journey = "<<journey<<endl;
    }
    if((source=="Nottingham" && destination == "Manchester")||((source=="Manchester" && destination == "Nottingham"))){

        journey = 40;
        cout<<"journey = "<<journey<<endl;
    }
    if((source=="Nottingham" && destination == "London")||((source=="London" && destination == "Nottingham"))){

        journey = 90;
        cout<<"journey = "<<journey<<endl;
    }
    if (lorrySize == "small"){
        lorryCharge = 1;
    } else if (lorrySize == "medium"){
        lorryCharge = 1.5;
    } else if (lorrySize == "large"){
        lorryCharge = 2;
    }

    QString noOfParcelsQ = ui->ParcelsInput->text();
    int noOfParcelsInt = noOfParcelsQ.toInt();
    float Cost = ((noOfParcelsInt*amountPerParcel*lorryCharge)+journey);
    QString costQString = QString::number(Cost);
    QMessageBox::information(this,"Order Quote","The cost for this order would be: £" + costQString);
}


void ownerWindow::on_Submitfeedback_clicked()
{
    ///on_Submitfeedback_clicked()

    ///

    ///A function codes a button so that when clicked, the feedback will be pushed to the company.

    ///@param name is a parameter type QString that stores the name of the user.

    ///@param Email is a parameter type QString that stores the Email of the user.

     ///@param OrderID is a parameter type QString that stores the OrderID of the user.

    ///@param Message is a parameter type QString that stores the Message of the user.

    ///@param UserType is a parameter type QString that stores the type of the user.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

    QString Name = ui->nameLineEdit->text();
    QString Email = ui->emailLineEdit->text();
    QString OrderID = ui->orderIDLineEdit->text();
    QString Message = ui->messageLineEdit->text();
    QString UserType = "Cargo Owner";

    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("127.0.0.1");
    DB.setUserName("admin");
    DB.setPassword("lGArctrtpM7I");
    DB.setDatabaseName("E-TransportDB");

    if(DB.open()){
        QSqlQuery Qry;
        QString sql_code = "INSERT INTO ";
        sql_code+= TB_NAME6;
        sql_code += "(Name,UserType,Email,OrderID,Message)VALUES(:Name,:UserType,:Email,:OrderID,:Message)";
        Qry.prepare(sql_code);
        Qry.bindValue(":Name",Name);
        Qry.bindValue(":UserType",UserType);
        Qry.bindValue(":Email",Email);
        Qry.bindValue(":OrderID",OrderID);
        Qry.bindValue(":Message",Message);
        if (Qry.exec()){
            QMessageBox::information(this, "Feedback Submitted", "Thank you for your Feedback");
        } else{
            QMessageBox::information(this, "Feedback Unsuccessful", "Please try again later");
        }
    }

    else{
        QMessageBox::warning(this,"No connection","Not connected to the database");

    }
}

void ownerWindow::on_ProfileBtn_2_clicked()
{

    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `CargoOwner`");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int nameIndex = rec.indexOf("Name");
     int emailIndex = rec.indexOf("Email");
     int phoneIndex = rec.indexOf("Phone");
     int addressIndex = rec.indexOf("Address");
     int usernameIndex = rec.indexOf("Username");
     int passwordIndex = rec.indexOf("Password");

          QString Name;
          QString Email;
          QString Phone;
          QString Address;
          QString Username;
          QString Password;



    while(qry.next()){

            Name = qry.value(nameIndex).toString();
            qDebug()<<qry.value(nameIndex).toString();

            Email = qry.value(emailIndex).toString();
            qDebug()<<qry.value(emailIndex).toString();

            Phone = qry.value(phoneIndex).toString();
            qDebug()<<qry.value(phoneIndex).toString();

            Address = qry.value(addressIndex).toString();
            qDebug()<<qry.value(addressIndex).toString();

            Username = qry.value(usernameIndex).toString();
            qDebug()<<qry.value(usernameIndex).toString();

            Password = qry.value(passwordIndex).toString();
            qDebug()<<qry.value(passwordIndex).toString();

    }

    ui->OUpdate_nameLineEdit->setText(Name);
    ui->OUpdate_emailLineEdit->setText(Email);
    ui->OUpdate_phoneLineEdit->setText(Phone);
    ui->OUpdate_addressLineEdit->setText(Address);
    ui->OUpdate_usernameLineEdit_2->setText(Username);
    ui->OUpdate_passwordLineEdit->setText(Password);

    ui->OWNameLabel->setText(Name);
    ui->OWEmailLabel->setText(Email);
    ui->OWPhoneLabel->setText(Phone);
    ui->OWaddressLabel->setText(Address);
    ui->OWusernameLabel->setText(Username);
    ui->OWpasswordLabel->setText(Password);

}

void ownerWindow::on_BookButton_3_clicked()
{
    ///on_BookButton_3_clicked()

    ///

    ///A function codes a button so that when clicked, the invoice will be printed to the user.

    ///@param Invoice amount is a parameter type QString that stores the name of the user.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()



    QMessageBox::information(this,"- - INVOICE - -", ""
                                                     "----------------------- \n"
                                                     "    Total cost = "+ui->InvoiceAmount->text()+"\n"
                                                                                                   "-----------------------");
}

void ownerWindow::on_SaveDetails_clicked()
{
    ///on_SaveDetails_clicked()

    ///

    ///A function codes a button so that when clicked, the changes values in the profile page will be updated in the database.

    ///@param name is a parameter type QString that stores the name of the user.

    ///@param Email is a parameter type QString that stores the Email of the user.

    ///@param Phone is a parameter type QString that stores the Phone of the user.

    ///@param Address is a parameter type QString that stores the Address of the user.

    ///@param Username is a parameter type QString that stores the Username of the user.

    ///@param Password is a parameter type QString that stores the Password of the user.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

    QString originalName = ui->OWNameLabel->text();

    QString Name = ui->OUpdate_nameLineEdit->text();
    QString Email = ui->OUpdate_emailLineEdit->text();
    QString Phone = ui->OUpdate_phoneLineEdit->text();
    QString Address = ui->OUpdate_addressLineEdit->text();
    QString Username = ui->OUpdate_usernameLineEdit_2->text();
    QString Password = ui->OUpdate_passwordLineEdit->text();

    //connect to database
        QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");


        if(DB.open()){

            QSqlQuery DelQry;
            QString sql_code2 = "DELETE FROM `CargoOwner` WHERE Name = '"+originalName+"'";
            DelQry.prepare(sql_code2);
            DelQry.exec();

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

void ownerWindow::on_ProfileBtn_3_clicked()
{
    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `CargoOwner`");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int nameIndex = rec.indexOf("Name");
     int emailIndex = rec.indexOf("Email");
     int phoneIndex = rec.indexOf("Phone");
     int addressIndex = rec.indexOf("Address");
     int usernameIndex = rec.indexOf("Username");
     int passwordIndex = rec.indexOf("Password");

          QString Name;
          QString Email;
          QString Phone;
          QString Address;
          QString Username;
          QString Password;



    while(qry.next()){

            Name = qry.value(nameIndex).toString();
            qDebug()<<qry.value(nameIndex).toString();

            Email = qry.value(emailIndex).toString();
            qDebug()<<qry.value(emailIndex).toString();

            Phone = qry.value(phoneIndex).toString();
            qDebug()<<qry.value(phoneIndex).toString();

            Address = qry.value(addressIndex).toString();
            qDebug()<<qry.value(addressIndex).toString();

            Username = qry.value(usernameIndex).toString();
            qDebug()<<qry.value(usernameIndex).toString();

            Password = qry.value(passwordIndex).toString();
            qDebug()<<qry.value(passwordIndex).toString();

    }

    ui->OUpdate_nameLineEdit->setText(Name);
    ui->OUpdate_emailLineEdit->setText(Email);
    ui->OUpdate_phoneLineEdit->setText(Phone);
    ui->OUpdate_addressLineEdit->setText(Address);
    ui->OUpdate_usernameLineEdit_2->setText(Username);
    ui->OUpdate_passwordLineEdit->setText(Password);

    ui->OWNameLabel->setText(Name);
    ui->OWEmailLabel->setText(Email);
    ui->OWPhoneLabel->setText(Phone);
    ui->OWaddressLabel->setText(Address);
    ui->OWusernameLabel->setText(Username);
    ui->OWpasswordLabel->setText(Password);
}

void ownerWindow::on_img_clicked()
{
    ///on_img_clicked()

    ///

    ///A function codes a button so that when clicked, a file window window is opened where a user can choose a profile picture.

    ///@param name is a parameter type QString that stores the file name of the image.

    ///@param name is a parameter type bool that stores the a value determining whether the picture is valid to place in the profile image window.

    ///@returns void

    ///@see on_SaveDetails_clicked() on_BookButton_3_clicked() on_Submitfeedback_clicked() on_BookButton_clicked() on_Profile_Btn_Menu_clicked() on_Order_Btn_Menu_clicked() SetupFunction() on_Logout_Btn_Menu_clicked() on_img_clicked()

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
