#include "mainwindow.h"
#include <iostream>
#include <string>
#include <QApplication>

using namespace std;

class cargoOwner_login{
      private:
          string username, password;
  public:
      string login()
      {
          username="";
          password="";
          return 0;
      };
      bool IsLogin();
  };

bool cargoOwner_login :: IsLogin() {
  cin>>username;
  cin>>password;
  return 0;
};

class Driver_login{
      private:
          string username, password;
  public:
     string login()
      {
          username="";
          password="";
          return 0;
      };
      bool IsLogin();
  };

bool Driver_login :: IsLogin() {
  cin>>username;
 cin>>password;
 return 0;
};

class Transport_login{
      private:
          string username, password;
  public:
      string login()
      {
          username="";
          password="";
          return 0;
      };
      bool IsLogin();
    };

bool Transport_login :: IsLogin() {
    cin>>username;
   cin>>password;
   return 0;
};

void logOff (){

}


class Register_Cargo{
  private://please make sure the objects here should be the same name while doing the UI
         string Fullname;
         string PhoneNo;
         string Address;
         string Email;
         string Username_3;
         string Password_3;
public:
         void Register();
         bool signUp();
};

void Register_Cargo::Register(){
    Fullname="";
    Email="";
    PhoneNo="";
    Address="";
    Username_3="";
    Password_3="";
};

bool Register_Cargo :: signUp() {
    cin>>Fullname;
    cin>>Email;
    cin>>PhoneNo;
    cin>>Address;
    cin>>Username_3;
   cin>>Password_3;
   return 0;
};

class Register_Driver{
  private://please make sure the objects here should be the same name while doing the UI
         string Fullname;
         string PhoneNo;
         string NInumber;
         string ID;
         string TypeOfLorry;
         string Address;
         string Email;
         string Username_2;
         string Password_2;
public:

};
class Register_Company{
  private://please make sure the objects here should be the same name while doing the UI
         string CompanyName;
         string PhoneNo;
         string Address;
         string Email;
         string Username_1;
         string Password_1;
public:

};








int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    using namespace std;


    cargoOwner_login c;
    Driver_login d;
    Transport_login t;
    c.IsLogin();
    d.IsLogin();
    t.IsLogin();




    return 0;
}

