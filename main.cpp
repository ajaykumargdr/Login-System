//Login System
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void MainMenu();
void Login();
void SignIn();

int main(){ system("color 0B");
  MainMenu();
}

void MainMenu(){
system("cls");

    int Choice;
    cout<<"1 : Login\n"
   <<"2 : Sign In\n"
   <<"3 : Exit\n"
   <<"Enter Your Choice : "; cin>>Choice;
   switch(Choice){
   case 1:Login();main();
   case 2:SignIn();main();
   case 3:exit(0);
   default : cout<<"\aYou Entered Wrong Number!\n";Sleep(10);main();

   }
}

void Login(){ system("color 0C"); system("cls");

cout<<"Login Page:-\n"
    <<"------------\n";

string Username,Password,UP; cout<<"Enter Username : ";cin.sync();
getline(cin,Username); cout<<"Enter Password : ";
cin.sync();
getline(cin,Password);

UP=Username+" "+Password;

    char input[50];
    ifstream in("NewLogin.txt");

bool User=0;while(in.getline(input,50)){if(UP==input) User=1;}

if(User==1)cout<<"Login SuccessFull!\n";
else cout<<"\aIncorrect Password Or User Name !\n";

system("pause");
in.close();
}

void SignIn(){system("color 06");system("cls");
cout<<"Sign in Page:-\n"
    <<"--------------\n";

string username;
char password[50];
cout<<"Enter Username : "; cin.sync(); getline(cin,username);
cout<<"Enter Password : ";
for(int i=0;;i++){
        cin.sync();
       int y=getch();
       if(y==8){i-=2;goto k;}
       if(y==13){password[i]='\0';break;}
       cout<<'*';
       password[i]=y;
    k:;
}
fstream out("NewLogin.txt",ios::app);
cin.sync();
out<<username<<" "<<password<<"\n";
out.close();
cout<<"\nSign in SuccessFull!\n";system("pause");
}
