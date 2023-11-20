#include "user.h"
using namespace std;
#include<iostream>
#include<fstream>
#include <string.h>

user::user(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
{
    username = _username;
    password = _password;
    access = _access;
    admin_access = _admin_access;
    co_cert = _co_cert_;
    visa_cert = _visa_cert_;
    balance = _balance_;
    save_user_direct();
    cout << "created succssfuly "<<endl;
}

/// ready to Run down
string user::give_access_username()
{
    return username;
}

string user::give_access_password()
{
    return password;
}

int user::give_access_access()
{
    return access;
}

int user::give_access_admin_access()
{
    return admin_access;
}

int user::give_access_co_cert()
{
    return co_cert;
}

int user::give_access_visa_cert()
{
    return visa_cert;
}

int user::give_access_balance()
{
    return balance;
}

void user::edit_access_username(string _user)
{
    username = _user;
}

void user::edit_access_password(string _password)
{
    password = _password;
}

void user::edit_access_access(int _access)
{
    access = _access;
}

void user::edit_access_admin_access(int _admin_access)
{
    admin_access = _admin_access;
}

void user::edit_access_co_cert(int _co_cert__)
{
    co_cert = _co_cert__;
}

void user::edit_access_visa_cert(int _visa_cert_)
{
    visa_cert = _visa_cert_;
}

void user::edit_access_balance(int _balance_)
{
    balance = _balance_;
}
///Readyy to RUN up
void save_user_direct() {
    ofstream finput("user.txt", ios::app);

    if (!finput.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    // Assuming give_access_username, give_access_password, etc., are member functions that return the values.
    finput << user::give_access_username << " " << user::give_access_password << " ";
    finput << user::give_access_access << " " << user::give_access_admin_access << " ";
    finput << user::give_access_co_cert << " " << user::give_access_visa_cert << " ";
    finput << user::give_access_balance << endl;
    finput.close();
}
// string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_
user extract_info_username(string username_) {
    ifstream foutput("user.txt");
    string str[2];
    int arr[5];
    while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
    {
        if(str[0] == username_){
            user u1;
            u1.edit_access_username(str[0]);
            u1.edit_access_password(str[1]);
            u1.edit_access_access(arr[0]);
            u1.edit_access_admin_access(arr[1]);
            u1.edit_access_co_cert(arr[2]);
            u1.edit_access_visa_cert(arr[3]);
            u1.edit_access_balance(arr[4]);
            return u1;
            }
    }
} //ifsr
int delete_username(string username_) {

}
int print_info_username(string username_) {
    ifstream foutput("user.txt");
    string str[2];
    int arr[5];
    while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
    {
        if(str[0] == username_){
            user u1;
            u1.edit_access_username(str[0]);
            u1.edit_access_password(str[1]);
            u1.edit_access_access(arr[0]);
            u1.edit_access_admin_access(arr[1]);
            u1.edit_access_co_cert(arr[2]);
            u1.edit_access_visa_cert(arr[3]);
            u1.edit_access_balance(arr[4]);
            return u1;
            }
    }
}
int search_username(string username_) {
    
} //ifsr
int print_user_operation(string username_) {}
void save_user_operation(string username_,int id_,int value) {}
int return_user_operation(string username_,int id_,int value) {}
