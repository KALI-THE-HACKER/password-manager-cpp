/*
A simple C++ Password manager tool, which will store your passwords in encrypted form and save them in a folder name data in the same directory as this tool.

Operating System : Windows [windows 7 tested]

Author : Lucky verma

Date created : 21 - 22 Jul 2021

    +This tool is a part of my C++ begginer projects+

Follow me on : Instagram - @K4L1_TH3_H4CK3R_ (instagram.com/k4l1_th3_h4ck3r_)
               Twitter - @Luckyve28366346 (twitter.com/Luckyve28366346)

*/


// Importing header files
#include<iostream>
#include<fstream>
#include "windows.h"
#include <dirent.h>
#include <sys/types.h>

using namespace std;


void login()
{
    string username, password, u_name, passwd, u_name1, passwd1;
    void signup();

    string encrypt(string password);

    fstream login_file;
    login_file.open("./data/kali-database", ios::in);
    
    getline(login_file, username);
    getline(login_file, password);

    if(username=="" || username==" ")
    {
        signup();
    } 

    cout<<"Log-in to use this tool\n"<<endl;
    cout<<"USERNAME : ";
    cin>>u_name1;
    cout<<"PASSWORD : ";
    cin>>passwd1;

    u_name = encrypt(u_name1);
    passwd = encrypt(passwd1);

    if(username==u_name)
    {
        if(password==passwd)
        {
            cout<<"\nLogged in Succesfully!\n"<<endl;
        }

        else{
            cout<<"\nWrong Username or password! Please try again;"<<endl<<endl;
            login();
        }
    }
    else{
        cout<<"\nWrong Username or password! Please try again;"<<endl<<endl;
        login();
    }

}

void signup()
{
    string encrypt(string password);
    string u_name1, passwd1, confirm_passwd, u_name, passwd;
    
    cout<<"Please sign-up below in order to make this tool more secure and remember your username and password!\n"<<endl;

    cout<<"USERNAME : ";
    cin>>u_name1;
    cout<<"PASSWORD : ";
    cin>>passwd1;
    cout<<"CONFIRM PASSWORD : ";
    cin>>confirm_passwd;

    if(passwd1==confirm_passwd)
    {
        cout<<"\nSaving data...\n"<<endl;
    }
    else{
        signup();
    }

    u_name = encrypt(u_name1);
    passwd = encrypt(passwd1);


    fstream signup_file;
    signup_file.open("./data/kali-database");
    signup_file<<u_name<<"\n";
    signup_file<<passwd<<"\n";
    signup_file<<"pass@1234"<<"\n"; //free strings for unknown users, who would see the pasword file
    signup_file<<"pnjkh@#ak"<<"\n"; //^^^^
    signup_file<<"njfkejnc~k";//^^^^
    signup_file.close();

}

void save()
{
    string app_name, u_name, passwd, email, confirm_passwd, password;

    cout<<"App or website name : ";
    cin>>app_name;
    cout<<"\n";
    if(app_name=="kali-database")
    {
        cout<<"\nYou cannot edit this file!\n";
        save();
    }

    cout<<"Username : ";
    cin>>u_name;
    cout<<"E-mail or Phone : ";
    cin>>email;
    cout<<"Password : ";
    cin>>passwd;
    cout<<"Confirm Password : ";
    cin>>confirm_passwd;
    cout<<"\n";

    if(passwd!=confirm_passwd)
    {
        cout<<"Passwords do not match, please try again!"<<endl<<endl;
        save();
    }

    else
    {
        string encrypt(string password);
        password = encrypt(passwd);
        cout<<"saving data..."<<endl;
        fstream data_file;
        data_file.open("./Data/"+app_name, ios::out);
        data_file<<"Username : "<<u_name<<"\n";
        data_file<<"E-mail : "<<email<<"\n";
        data_file<<password;
        data_file.close();
    }
}

void show()
{
    string decrypt(string password);
    string app_name, u_name, email, passwd, u_name1, email1, passwd1, u_name2, passwd2;


    cout<<"App or website name : ";
    cin>>app_name;

    fstream data_file;
    data_file.open("./data/"+app_name, ios::in);
    if(data_file.is_open()){
        getline(data_file, u_name);
        getline(data_file, email);
        getline(data_file, passwd);
    }

    else{
        cout<<"\nNo password data related to your search found! Try again;"<<endl<<endl;
        show();
    }

    string password = decrypt(passwd);

    cout<<u_name<<endl;
    cout<<email<<endl;
    cout<<"Password : "<<password<<endl<<endl;
   
}

void update()
{
    string decrypt(string password);
    string app_name, u_name, email, passwd, u_name1, email1, passwd1, u_name2, passwd2, confirm_passwd;


    cout<<"App or website name : ";
    cin>>app_name;
    if(app_name=="kali-database")
    {
        cout<<"\nYou cannot edit this file!\n";
        update();
    }

    fstream data_file;
    data_file.open("./data/"+app_name, ios::in);
    if(data_file.is_open()){
        getline(data_file, u_name);
        getline(data_file, email);
        getline(data_file, passwd);
    }

    else{
        cout<<"\nNo password data related to your search found! Try again;"<<endl<<endl;
        update();
    }

    string password = decrypt(passwd);

    cout<<"Old "<<u_name<<endl;
    cout<<"Old "<<email<<endl;
    cout<<"Old Password : "<<password<<endl<<endl;


    cout<<"New Username : ";
    cin>>u_name;
    cout<<"New E-mail or Phone : ";
    cin>>email;
    cout<<"New Password : ";
    cin>>passwd;
    cout<<"Confirm Password : ";
    cin>>confirm_passwd;
    cout<<"\n";

    if(passwd!=confirm_passwd)
    {
        cout<<"Passwords do not match, please try again!"<<endl<<endl;
        save();
    }

    else
    {
        string encrypt(string password);
        password = encrypt(passwd);
        cout<<"saving data...\n"<<endl;
        fstream data_file;
        data_file.open("./Data/"+app_name, ios::out);
        data_file<<"Username : "<<u_name<<"\n";
        data_file<<"E-mail : "<<email<<"\n";
        data_file<<password;
        data_file.close();
    }
}

void del()
{
    string app_name, app_name1, sure;
    cout<<"App or website name : ";
    cin>>app_name;
    if(app_name=="kali-database")
    {
        cout<<"\nYou cannot delete this file!\n";
        del();
    }
    cout<<"Are you sure to want to delete password data of "<<app_name<<"? [y/n] : "<<endl;
    cin>>sure;
    if(sure=="y" || sure=="yes")
    {
        app_name1 = "./data/"+app_name;
        remove(string(app_name1).c_str());
    }

    else if(sure=="n" || sure=="no")
    {
        cout<<"\n";
    }

    else{
        cout<<"Invalid choice!\n"<<endl;
    }

}

void change_passwd()
{
    string decrypt(string password);
    string u_name, passwd, confirm_passwd, passwd1, u_name1;

    fstream data_file;
    data_file.open("./data/kali-database", ios::in);
    if(data_file.is_open()){
        getline(data_file, u_name);
        getline(data_file, passwd);
    }

    else{
        cout<<"\nNo password data related to your search found! Try again;"<<endl<<endl;
        change_passwd();
    }

    string username = decrypt(u_name);
    string password = decrypt(passwd);

    cout<<"Old Username : "<<username<<endl;
    cout<<"Old Password : "<<password<<endl<<endl;


    cout<<"New Username : ";
    cin>>u_name;
    cout<<"New Password : ";
    cin>>passwd;
    cout<<"Confirm Password : ";
    cin>>confirm_passwd;
    cout<<"\n";

    if(passwd!=confirm_passwd)
    {
        cout<<"Passwords do not match, please try again!"<<endl<<endl;
        change_passwd();
    }

    else
    {
        string encrypt(string password);
        password = encrypt(passwd);
        username = encrypt(u_name);

        cout<<"saving data...\n"<<endl;
        fstream data_file;
        data_file.open("./Data/kali-database", ios::out);
        data_file<<username<<"\n";
        data_file<<password<<"\n";
        data_file<<"pasj127\n";
        data_file<<"pass@wrtg7";
        data_file.close();
    }
}


string encrypt(string password)
{
    int i;

    // char password[100];

    for(i = 0; (i < 100 && password[i] != '\0'); i++)
        password[i] = password[i] + 6;

        //  cout << "\nEncrypted string: " << password << endl;
        return password;

}

string decrypt(string password)
{
    int i;

    // char password[100];

    for(i = 0; (i < 100 && password[i] != '\0'); i++)
        password[i] = password[i] - 6;

        //  cout << "\nEncrypted string: " << password << endl;
        return password;

}


void list_dir(const char *path) {
   struct dirent *entry;
   DIR *dir = opendir(path);
   
   if (dir == NULL) {
      return;
   }
   while ((entry = readdir(dir)) != NULL) {
   cout << entry->d_name << endl;
   }
   closedir(dir);
}

void list()
{
    cout<<"List of all available apps with data -\n"<<endl;
    void list_dir(const char *path);
    list_dir("./data/");
    cout<<"\n";
}



int main() {

    string choice;

    system("color a");
    cout<<"Hello sir, welcome in Kali password manager!"<<endl<<endl;
    sleep(1);
    
    login();

    while(true){
        cout<<"Choose your option :\n"<<endl;
        cout<<"[1] Save a new password data."<<endl;
        cout<<"[2] Show a password data."<<endl;
        cout<<"[3] Show list of all password data."<<endl;
        cout<<"[4] Update a password data."<<endl;
        cout<<"[5] Delete a password data."<<endl;
        cout<<"[6] Change tool's password."<<endl;
        cout<<"[7] Exit."<<endl;
        cout<<"\n >  ";
        cin>>choice;
        cout<<"\n";
        try
        {
            if(choice=="1")
            {
                save();
            }
            else if(choice=="2"){
                show();
            }
            else if(choice=="3"){
                list();
            }
            else if(choice=="4"){
                update();
            }
            else if(choice=="5"){
                del();
            }
            else if(choice=="6"){
                change_passwd();
            }
            else if(choice=="7"){
                exit(0);
            }
            
            else{
                cout<<"OPPS! Invalid option;\n"<<endl;
                main();
                // break;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout<<"[ERROR] : error while executing the programe!"<<endl;
        }
    }

}