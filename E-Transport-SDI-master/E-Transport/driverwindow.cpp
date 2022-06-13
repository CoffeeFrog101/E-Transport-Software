#include "driverwindow.h"
#include "ui_driverwindow.h"

driverWindow::driverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::driverWindow)
{
    //SetupFunction()

    ///

    ///A command that sets up the ui page and assigns prewritten “placeholders” for the lineEdit boxes when the page is loaded

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

    ui->setupUi(this);

    ui->nameLineEdit->setPlaceholderText("Press 'View my details'");
    ui->emailLineEdit->setPlaceholderText("Press 'View my details'");
    ui->driverIDLineEdit->setPlaceholderText("Press 'View my details'");
    ui->phoneLineEdit->setPlaceholderText("Press 'View my details'");
    ui->addressLineEdit->setPlaceholderText("Press 'View my details'");
    ui->usernameLineEdit->setPlaceholderText("Press 'View my details'");
    ui->passwordLineEdit->setPlaceholderText("Press 'View my details'");
    ui->nINLineEdit->setPlaceholderText("Press 'View my details'");
    ui->certificateNoCPCLineEdit->setPlaceholderText("Press 'View my details'");
    ui->lorryRegNoLineEdit_2->setPlaceholderText("Press 'View my details'");
    ui->lorryDimensionLineEdit_2->setPlaceholderText("Press 'View my details'");
    ui->lorryWeightLineEdit_2->setPlaceholderText("Press 'View my details'");


}

driverWindow::~driverWindow()
{
    delete ui;
}
void driverWindow::on_Home_Btn_Menu_2_clicked()
{
      ui->DriverPages->setCurrentIndex(0);
}

void driverWindow::on_Order_Btn_Menu_2_clicked()
{
      ui->DriverPages->setCurrentIndex(1);

}

void driverWindow::on_Profile_Btn_Menu_2_clicked()
{
      ui->DriverPages->setCurrentIndex(2);
}


void driverWindow::on_Feedback_Btn_Menu_2_clicked()
{
      ui->DriverPages->setCurrentIndex(4);
}

void driverWindow::on_ProfileBtn_2_clicked()
{
    ///on_ProfileBtn_2_clicked()

    ///

    ///A function codes a button so that when clicked, the profile information will be pasted inside the profile window.

    ///@param nameIndex is a parameter type integer used to retrieve the table index value of Name from the phptable. (emailIndex, phoneIndex, addressIndex, usernameIndex, passwordIndex, IDIndex, NINIndex, CPCIndex, RegNoIndex, DimensionIndex, WeightIndex carry out the same actions for their specific columns.)

    ///@param Name is a parameter type String that stores the value of Name retrieved from the phptable. (Email, phone, address, username, password, ID, NIN, CPC, Reg, Dimension, Weight carry out the same actions for their specific columns.)

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

      ui->DriverProfilePages->setCurrentIndex(1);

      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Driver`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");
       int IDIndex = rec.indexOf("ID");
       int NINIndex = rec.indexOf("NIN");
       int CPCIndex = rec.indexOf("CPC");
       int Regndex = rec.indexOf("LorryReg");
       int DimenIndex = rec.indexOf("LorryDimension");
       int WeightIndex = rec.indexOf("LorryWeight");


            QString Name;
            QString Email;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;
            QString DriverID;
            QString NIN;
            QString CPC;
            QString RegNo;
            QString Dimension;
            QString Weight;



      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();


              DriverID = qry.value(IDIndex).toString();
              qDebug()<<qry.value(IDIndex).toString();


              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

              NIN = qry.value(NINIndex).toString();
              qDebug()<<qry.value(NINIndex).toString();

              CPC = qry.value(CPCIndex).toString();
              qDebug()<<qry.value(CPCIndex).toString();

              RegNo = qry.value(Regndex).toString();
              qDebug()<<qry.value(Regndex).toString();

              Dimension = qry.value(DimenIndex).toString();
              qDebug()<<qry.value(DimenIndex).toString();

              Weight = qry.value(WeightIndex).toString();
              qDebug()<<qry.value(WeightIndex).toString();

      }

      ui->nameLineEdit->setText(Name);
      ui->emailLineEdit->setText(Email);
      ui->driverIDLineEdit->setText(DriverID);
      ui->phoneLineEdit->setText(Phone);
      ui->addressLineEdit->setText(Address);
      ui->usernameLineEdit->setText(Username);
      ui->passwordLineEdit->setText(Password);
      ui->nINLineEdit->setText(NIN);
      ui->certificateNoCPCLineEdit->setText(CPC);
      ui->lorryRegNoLineEdit_2->setText(RegNo);
      ui->lorryDimensionLineEdit_2->setText(Dimension);
      ui->lorryWeightLineEdit_2->setText(Weight);

      ui->nameLabel_4->setText(Name);
      ui->emailLabelD->setText(Email);
      ui->DriverIDLabel->setText(DriverID);
      ui->PhoneLabel->setText(Phone);
      ui->AddressLabel->setText(Address);
      ui->UsernameLabel->setText(Username);
      ui->PasswordLabel->setText(Password);
      ui->NINLabel->setText(NIN);
      ui->CPCLabel->setText(CPC);
      ui->RegLabel->setText(RegNo);
      ui->DimLabel->setText(Dimension);
      ui->WeightLabel->setText(Weight);
}

void driverWindow::on_Editprofilebtn_2_clicked()
{
      ui->DriverProfilePages->setCurrentIndex(0);

      QSqlQuery qry(QSqlDatabase::database("MyConnect"));
      QString sql_code2 = ("SELECT * FROM `Driver`");
      qry.prepare(sql_code2);
      qry.exec();
      QSqlRecord rec = qry.record();
      int nameIndex = rec.indexOf("Name");
       int emailIndex = rec.indexOf("Email");
       int phoneIndex = rec.indexOf("Phone");
       int addressIndex = rec.indexOf("Address");
       int usernameIndex = rec.indexOf("Username");
       int passwordIndex = rec.indexOf("Password");
       int IDIndex = rec.indexOf("ID");
       int NINIndex = rec.indexOf("NIN");
       int CPCIndex = rec.indexOf("CPC");
       int Regndex = rec.indexOf("LorryReg");
       int DimenIndex = rec.indexOf("LorryDimension");
       int WeightIndex = rec.indexOf("LorryWeight");


            QString Name;
            QString Email;
            QString Phone;
            QString Address;
            QString Username;
            QString Password;
            QString DriverID;
            QString NIN;
            QString CPC;
            QString RegNo;
            QString Dimension;
            QString Weight;



      while(qry.next()){

              Name = qry.value(nameIndex).toString();
              qDebug()<<qry.value(nameIndex).toString();

              Email = qry.value(emailIndex).toString();
              qDebug()<<qry.value(emailIndex).toString();


              DriverID = qry.value(IDIndex).toString();
              qDebug()<<qry.value(IDIndex).toString();


              Phone = qry.value(phoneIndex).toString();
              qDebug()<<qry.value(phoneIndex).toString();

              Address = qry.value(addressIndex).toString();
              qDebug()<<qry.value(addressIndex).toString();

              Username = qry.value(usernameIndex).toString();
              qDebug()<<qry.value(usernameIndex).toString();

              Password = qry.value(passwordIndex).toString();
              qDebug()<<qry.value(passwordIndex).toString();

              NIN = qry.value(NINIndex).toString();
              qDebug()<<qry.value(NINIndex).toString();

              CPC = qry.value(CPCIndex).toString();
              qDebug()<<qry.value(CPCIndex).toString();

              RegNo = qry.value(Regndex).toString();
              qDebug()<<qry.value(Regndex).toString();

              Dimension = qry.value(DimenIndex).toString();
              qDebug()<<qry.value(DimenIndex).toString();

              Weight = qry.value(WeightIndex).toString();
              qDebug()<<qry.value(WeightIndex).toString();

      }

      ui->nameLineEdit->setText(Name);
      ui->emailLineEdit->setText(Email);
      ui->driverIDLineEdit->setText(DriverID);
      ui->phoneLineEdit->setText(Phone);
      ui->addressLineEdit->setText(Address);
      ui->usernameLineEdit->setText(Username);
      ui->passwordLineEdit->setText(Password);
      ui->nINLineEdit->setText(NIN);
      ui->certificateNoCPCLineEdit->setText(CPC);
      ui->lorryRegNoLineEdit_2->setText(RegNo);
      ui->lorryDimensionLineEdit_2->setText(Dimension);
      ui->lorryWeightLineEdit_2->setText(Weight);

      ui->nameLabel_4->setText(Name);
      ui->emailLabelD->setText(Email);
      ui->DriverIDLabel->setText(DriverID);
      ui->PhoneLabel->setText(Phone);
      ui->AddressLabel->setText(Address);
      ui->UsernameLabel->setText(Username);
      ui->PasswordLabel->setText(Password);
      ui->NINLabel->setText(NIN);
      ui->CPCLabel->setText(CPC);
      ui->RegLabel->setText(RegNo);
      ui->DimLabel->setText(Dimension);
      ui->WeightLabel->setText(Weight);
}

void driverWindow::on_Logout_Btn_Menu_clicked()
{
    ///on_CLogout_Btn_Menu_clicked()

    ///

    ///A function codes a button so that when clicked, the user can log out of the session.

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

    this->hide();

    QWidget *parent = this->parentWidget();
    parent->show();
}

void driverWindow::on_Loadtable_clicked()
{
    ///on_Loadtable_clicked()

    ///

    ///A function codes a button so that when clicked, the desired php SQL table will be pasted in the tableview window.

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()



    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
        DB.setHostName("127.0.0.1");
        DB.setUserName("admin");
        DB.setPassword("lGArctrtpM7I");
        DB.setDatabaseName("E-TransportDB");

        if(DB.open()){

            QSqlQuery qry(QSqlDatabase::database("MyConnect"));
            QString sql_code = ("SELECT  OrderID,Source,Destination,Cost FROM `Orders`");
            QSqlQueryModel * modal = new QSqlQueryModel();
            qry.prepare(sql_code);
            qry.exec();
            modal->setQuery(qry);
            ui->tableView2->setModel(modal);


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



                    ui->selectOrderIDComboBox_2->addItem(orderID);


            }


        } else{
            QMessageBox::information(this,"Connection error","not connected to database");
        }
}





void driverWindow::on_pushButton_clicked()
{

    ///on_pushButton_clicked()

    ///

    ///A function codes a button so that when clicked, the commission will be printed to the user.

    ///@param Invoice amount is a parameter type QString that stores the name of the user.

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

    QString acceptedOrder = ui->selectOrderIDComboBox_2->currentText();


    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `Orders` WHERE OrderID = '"+acceptedOrder+"'");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int orderIDindex = rec.indexOf("OrderID");
     int costIndex = rec.indexOf("Cost");
      int trackingIDindex = rec.indexOf("TrackingID");
       int statusIndex = rec.indexOf("Status");
     int sourceIndex = rec.indexOf("Source");
      int destinationIndex = rec.indexOf("Destination");
       int typeIndex = rec.indexOf("Type");
        int weightIndex = rec.indexOf("Weight");
         int widthIndex = rec.indexOf("Width");
          int lengthIndex = rec.indexOf("Length");

          QString OrderID;
          QString costQ;
          QString TrackingID;
          QString Status;
          QString Source;
          QString Destination;
          QString Type;
          QString weightQ;
          QString widthQ;
          QString lengthQ;


    while(qry.next()){

            OrderID = qry.value(orderIDindex).toString();
            qDebug()<<qry.value(orderIDindex).toString();

            costQ = qry.value(costIndex).toString();
            qDebug()<<qry.value(costIndex).toString();

            TrackingID = qry.value(trackingIDindex).toString();
            qDebug()<<qry.value(trackingIDindex).toString();

            Status = qry.value(statusIndex).toString();
            qDebug()<<qry.value(statusIndex).toString();

            Source = qry.value(sourceIndex).toString();
            qDebug()<<qry.value(sourceIndex).toString();

            Destination = qry.value(destinationIndex).toString();
            qDebug()<<qry.value(destinationIndex).toString();

            Type = qry.value(typeIndex).toString();
            qDebug()<<qry.value(typeIndex).toString();

            weightQ = qry.value(weightIndex).toString();
            qDebug()<<qry.value(weightIndex).toString();

            widthQ = qry.value(widthIndex).toString();
            qDebug()<<qry.value(widthIndex).toString();

            lengthQ = qry.value(lengthIndex).toString();
            qDebug()<<qry.value(lengthIndex).toString();

    }

    int Length = lengthQ.toInt();
    int Width = widthQ.toInt();
    int Weight = weightQ.toInt();
    int Cost = costQ.toInt();

    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("127.0.0.1");
    DB.setUserName("admin");
    DB.setPassword("lGArctrtpM7I");
    DB.setDatabaseName("E-TransportDB");

    if(DB.open()){


        //insert data into
        QSqlQuery Qry;
        QString sql_code = "INSERT INTO ";
        sql_code+= TB_NAME5;
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
             QMessageBox::information(this,"Order Accepted","You have accepted this order");
             QSqlQuery qry(QSqlDatabase::database("MyConnect"));
             QString sql_code = ("SELECT * FROM `AcceptedOrders`");
             QSqlQueryModel * modal = new QSqlQueryModel();
             qry.prepare(sql_code);
             qry.exec();
             modal->setQuery(qry);
             ui->tableView->setModel(modal);


             //puts the OrderIDs into the comboBox to be selected
             QSqlQuery qry2(QSqlDatabase::database("MyConnect"));
             QString sql_code3 = ("SELECT * FROM `AcceptedOrders`");
             qry2.prepare(sql_code3);
             QString orderID;
             qry2.exec();
             QSqlRecord rec1 = qry2.record();
             int orderIDindex1 = rec1.indexOf("OrderID");

             while(qry2.next()){

                     orderID = qry2.value(orderIDindex1).toString();
                     qDebug()<<qry2.value(orderIDindex1).toString();



                     ui->selectOrderIDComboBox->addItem(orderID);


             }

         }
         else{
             QMessageBox::warning(this,"Failed","Data has fail to insert");
         }
    }

    else{
        QMessageBox::warning(this,"No connection","Not connected to the database");

    }




}




void driverWindow::on_updateStatusButton_clicked()
{






    QString Status = ui->updateStatusComboBox->currentText();
    QString previousVersion = ui->selectOrderIDComboBox->currentText();

    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `AcceptedOrders`");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int orderIDindex = rec.indexOf("OrderID");
     int costIndex = rec.indexOf("Cost");
      int trackingIDindex = rec.indexOf("TrackingID");
     int sourceIndex = rec.indexOf("Source");
      int destinationIndex = rec.indexOf("Destination");
       int typeIndex = rec.indexOf("Type");
        int weightIndex = rec.indexOf("Weight");
         int widthIndex = rec.indexOf("Width");
          int lengthIndex = rec.indexOf("Length");

          QString OrderID;
          QString costQ;
          QString TrackingID;
          QString Source;
          QString Destination;
          QString Type;
          QString weightQ;
          QString widthQ;
          QString lengthQ;


    while(qry.next()){

            OrderID = qry.value(orderIDindex).toString();
            qDebug()<<qry.value(orderIDindex).toString();

            costQ = qry.value(costIndex).toString();
            qDebug()<<qry.value(costIndex).toString();

            TrackingID = qry.value(trackingIDindex).toString();
            qDebug()<<qry.value(trackingIDindex).toString();

            Source = qry.value(sourceIndex).toString();
            qDebug()<<qry.value(sourceIndex).toString();

            Destination = qry.value(destinationIndex).toString();
            qDebug()<<qry.value(destinationIndex).toString();

            Type = qry.value(typeIndex).toString();
            qDebug()<<qry.value(typeIndex).toString();

            weightQ = qry.value(weightIndex).toString();
            qDebug()<<qry.value(weightIndex).toString();

            widthQ = qry.value(widthIndex).toString();
            qDebug()<<qry.value(widthIndex).toString();

            lengthQ = qry.value(lengthIndex).toString();
            qDebug()<<qry.value(lengthIndex).toString();

    }

    int Length = lengthQ.toInt();
    int Width = widthQ.toInt();
    int Weight = weightQ.toInt();
    int Cost = costQ.toInt();

    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("127.0.0.1");
    DB.setUserName("admin");
    DB.setPassword("lGArctrtpM7I");
    DB.setDatabaseName("E-TransportDB");

    if(DB.open()){


        QSqlQuery DelQry;
        QString sql_code2 = "DELETE FROM `AcceptedOrders` WHERE OrderID = '"+previousVersion+"'";
        DelQry.prepare(sql_code2);
        DelQry.exec();
        QSqlQuery DelQry2;
        QString sql_code3 = "DELETE FROM `Orders` WHERE OrderID = '"+previousVersion+"'";
        DelQry2.prepare(sql_code3);
        DelQry2.exec();

        //insert data into
        QSqlQuery InsQry;
        QString sql_code_ins = "INSERT INTO ";
        sql_code_ins+= TB_NAME4;
        sql_code_ins += "(OrderID,Cost,TrackingID,Status,Source,Destination,Type,Weight,Width,Length)VALUES(:OrderID,:Cost,:TrackingID,:Status,:Source,:Destination,:Type,:Weight,:Width,:Length)";
        InsQry.prepare(sql_code_ins);
         InsQry.bindValue(":OrderID",OrderID);
         InsQry.bindValue(":Cost",Cost);
         InsQry.bindValue(":TrackingID",TrackingID);
         InsQry.bindValue(":Status",Status);
         InsQry.bindValue(":Source",Source);
         InsQry.bindValue(":Destination",Destination);
         InsQry.bindValue(":Type",Type);
         InsQry.bindValue(":Weight",Weight);
         InsQry.bindValue(":Width",Width);
         InsQry.bindValue(":Length",Length);
         InsQry.exec();

        //insert data into
         QSqlQuery Qry;
         QString sql_code = "INSERT INTO ";
         sql_code+= TB_NAME5;
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
             QMessageBox::information(this,"Status Updated","You have updated the status of this order");
             QSqlQuery qry(QSqlDatabase::database("MyConnect"));
             QString sql_code = ("SELECT * FROM `AcceptedOrders`");
             QSqlQueryModel * model = new QSqlQueryModel();
             qry.prepare(sql_code);
             qry.exec();
             model->setQuery(qry);
             ui->tableView->setModel(model);

         }
         else{
             QMessageBox::warning(this,"Failed","Data has fail to insert");
         }
    }

    else{
        QMessageBox::warning(this,"No connection","Not connected to the database");

    }
}


void driverWindow::on_Submitfeedback_2_clicked()
{

    QString Name = ui->FDnameLineEdit->text();
    QString Email = ui->FDemailLineEdit->text();
    QString OrderID = ui->FDorderIDLineEdit->text();
    QString Message = ui->FDmessageLineEdit->text();
    QString UserType = "Driver";

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

void driverWindow::on_ViewDetail_clicked()
{

    QSqlQuery qry(QSqlDatabase::database("MyConnect"));
    QString sql_code2 = ("SELECT * FROM `Driver`");
    qry.prepare(sql_code2);
    qry.exec();
    QSqlRecord rec = qry.record();
    int nameIndex = rec.indexOf("Name");
     int emailIndex = rec.indexOf("Email");
     int phoneIndex = rec.indexOf("Phone");
     int addressIndex = rec.indexOf("Address");
     int usernameIndex = rec.indexOf("Username");
     int passwordIndex = rec.indexOf("Password");
     int IDIndex = rec.indexOf("ID");
     int NINIndex = rec.indexOf("NIN");
     int CPCIndex = rec.indexOf("CPC");
     int Regndex = rec.indexOf("LorryReg");
     int DimenIndex = rec.indexOf("LorryDimension");
     int WeightIndex = rec.indexOf("LorryWeight");


          QString Name;
          QString Email;
          QString Phone;
          QString Address;
          QString Username;
          QString Password;
          QString DriverID;
          QString NIN;
          QString CPC;
          QString RegNo;
          QString Dimension;
          QString Weight;



    while(qry.next()){

            Name = qry.value(nameIndex).toString();
            qDebug()<<qry.value(nameIndex).toString();

            Email = qry.value(emailIndex).toString();
            qDebug()<<qry.value(emailIndex).toString();


            DriverID = qry.value(IDIndex).toString();
            qDebug()<<qry.value(IDIndex).toString();


            Phone = qry.value(phoneIndex).toString();
            qDebug()<<qry.value(phoneIndex).toString();

            Address = qry.value(addressIndex).toString();
            qDebug()<<qry.value(addressIndex).toString();

            Username = qry.value(usernameIndex).toString();
            qDebug()<<qry.value(usernameIndex).toString();

            Password = qry.value(passwordIndex).toString();
            qDebug()<<qry.value(passwordIndex).toString();

            NIN = qry.value(NINIndex).toString();
            qDebug()<<qry.value(NINIndex).toString();

            CPC = qry.value(CPCIndex).toString();
            qDebug()<<qry.value(CPCIndex).toString();

            RegNo = qry.value(Regndex).toString();
            qDebug()<<qry.value(Regndex).toString();

            Dimension = qry.value(DimenIndex).toString();
            qDebug()<<qry.value(DimenIndex).toString();

            Weight = qry.value(WeightIndex).toString();
            qDebug()<<qry.value(WeightIndex).toString();

    }

    ui->nameLineEdit->setText(Name);
    ui->emailLineEdit->setText(Email);
    ui->driverIDLineEdit->setText(DriverID);
    ui->phoneLineEdit->setText(Phone);
    ui->addressLineEdit->setText(Address);
    ui->usernameLineEdit->setText(Username);
    ui->passwordLineEdit->setText(Password);
    ui->nINLineEdit->setText(NIN);
    ui->certificateNoCPCLineEdit->setText(CPC);
    ui->lorryRegNoLineEdit_2->setText(RegNo);
    ui->lorryDimensionLineEdit_2->setText(Dimension);
    ui->lorryWeightLineEdit_2->setText(Weight);

    ui->nameLabel_4->setText(Name);
    ui->emailLabelD->setText(Email);
    ui->DriverIDLabel->setText(DriverID);
    ui->PhoneLabel->setText(Phone);
    ui->AddressLabel->setText(Address);
    ui->UsernameLabel->setText(Username);
    ui->PasswordLabel->setText(Password);
    ui->NINLabel->setText(NIN);
    ui->CPCLabel->setText(CPC);
    ui->RegLabel->setText(RegNo);
    ui->DimLabel->setText(Dimension);
    ui->WeightLabel->setText(Weight);

}

void driverWindow::on_SaveDetails_2_clicked()
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

    ///@param ID is a parameter type QString that stores the DriverID of the user.

    ///@param NIN is a parameter type QString that stores the National Insurance Number of the user.

    ///@param CPC is a parameter type QString that stores the CPC of the user.

    ///@param RegNo is a parameter type QString that stores the RegNo of the vehicle.

    ///@param Dimension is a parameter type QString that stores the Dimensions of the cargo.

    ///@param Weight is a parameter type QString that stores the weight of the cargo.

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

    QString originalName = ui->nameLabel_4->text();
    qDebug() << "Original name = " << originalName;

    QString Name = ui->nameLineEdit->text();
    QString Email = ui->emailLineEdit->text();
    QString ID = ui->driverIDLineEdit->text();
    QString Phone = ui->phoneLineEdit->text();
    QString Address = ui->addressLineEdit->text();
    QString Username = ui->usernameLineEdit->text();
    QString Password = ui->passwordLineEdit->text();
    QString NIN = ui->nINLineEdit->text();
    QString CPC = ui->certificateNoCPCLineEdit->text();
    QString LorryReg = ui->lorryRegNoLineEdit_2->text();
    QString LorryDimension = ui->lorryDimensionLineEdit_2->text();
    QString LorryWeight = ui->lorryWeightLineEdit_2->text();

    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("127.0.0.1");
    DB.setUserName("admin");
    DB.setPassword("lGArctrtpM7I");
    DB.setDatabaseName("E-TransportDB");

    if(DB.open()){


        QSqlQuery DelQry;
        QString sql_code2 = "DELETE FROM `Driver` WHERE Name = '"+originalName+"'";
        DelQry.prepare(sql_code2);
        DelQry.exec();


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
         Qry.exec();

         QMessageBox::information(this,"Details Saved","Your details have been updated");

    }

    else{
        QMessageBox::warning(this,"No connection","Not connected to the database");

    }
}



void driverWindow::on_img_clicked()
{

    ///on_img_clicked()

    ///

    ///A function codes a button so that when clicked, a file window window is opened where a user can choose a profile picture.

    ///@param name is a parameter type QString that stores the file name of the image.

    ///@param name is a parameter type bool that stores the a value determining whether the picture is valid to place in the profile image window.

    ///@returns void

    ///@see SetupFunction() on_ProfileBtn_2_clicked() on_Loadtable_clicked() on_CLogout_Btn_Menu_clicked() on_pushButton_clicked() on_SaveDetails_clicked() on_img_clicked()

    QString FileName = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));

    if(QString::compare(FileName,QString())!=0)
    {
        QImage img;
        bool valid = img.load(FileName);
        if(valid){
            img = img.scaledToWidth(ui->ProfileLogo_2->width(), Qt::SmoothTransformation);
            ui->ProfileLogo_2->setPixmap(QPixmap::fromImage(img));
        }
        else
        {
            //error handeling
        }
    }
}
