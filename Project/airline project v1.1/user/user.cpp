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
    finput << user::give_access_username << " " << user::give_access_password << " ";
    finput << user::give_access_access << " " << user::give_access_admin_access << " ";
    finput << user::give_access_co_cert << " " << user::give_access_visa_cert << " ";
    finput << user::give_access_balance << endl;
    finput.close();
}

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
    ifstream foutput("user.txt");
    string str[2];
    int arr[5];
    while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
    {
        if(str[0] == username_){
            return 1;
            }
    }
} 
int print_user_operation(string username_) {
    ifstream foutput("user.txt");
    string str[2];
    int arr[5];
    while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
    {
// string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_
        if(str[0] == username_){
            cout << "User Information : " <<endl;
            cout << "The User Name : " << str[0] <<endl;
            cout << "The User Password : " << str[1] <<endl;
            cout << "The User Access : " << >arr[0] <<endl;
            cout << "The User Admin Access : " << arr[1] <<endl;
            cout << "The User Covid-19 Certificate : " << arr[2] <<endl;
            cout << "The User Visa-Contry Certificate  : " << arr[3] <<endl;
            cout << "The User Balance : " << arr[4] <<endl;
            return 1;
            }
    }
}
void save_user_operation(string username_,int id_,int value) {
    try{
    ofstream finput("operation_user.txt", ios::app);
    if(!(fileinput.open())){
        //important file thats why 
    throw error_file_not_founded();
}
    finput << username_ << " " << id_ <<" "<< value <<endl ;
}
catch (error_file_not_founded){
    cerr << "File Not Founded , Check your Information !" << endl;
}
}
int return_user_operation(string username_,int id_,int value) {
try{
    int arr[2];
    string str;
    ifstream fileoutput("operation_user.txt");
    ofstream fileinput("operation_user_new.txt");
    if(!(foutput.open())){
        //important file thats why 
    throw error_file_not_founded();
}
while(foutput >> str >> arr[0] >> arr[1])
{
    if(id_ != arr[0]){
    fileinput << username_ << " " << id_ <<" "<< value <<endl ;
    }
}
finput.close();
foutput.close();
ifstream fileoutput("operation_user_new.txt");
ofstream fileinput("operation_user.txt");
while(foutput >> str >> arr[0] >> arr[1]){
    fileinput << username_ << " " << id_ <<" "<< value <<endl ;
}
finput.close();
foutput.close();
}
catch(error_file_not_founded){
    cerr << "File Not Founded , Check your Information !" << endl;
}
}

int delete_username(string username_) {
    int arr[5];
    string str[2];
    ifstream fileoutput("user.txt");
    ofstream fileinput("user_new.txt");
    while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
{
if(username_ != str[0]){
    finput << str[0] << " " << str[1] << " ";
    finput << arr[0] << " " << arr[1] << " ";
    finput << arr[2] << " " << arr[3] << " ";
    finput << arr[4] << endl;
}
}
finput.close();
foutput.close();
    ifstream fileoutput("user_new.txt");
    ofstream fileinput("user.txt");
while(foutput >>str[0] >> str[1] >>arr[0]>> arr[1] >> arr[2]>> arr[3] >> arr[4])
{
    finput << str[0] << " " << str[1] << " ";
    finput << arr[0] << " " << arr[1] << " ";
    finput << arr[2] << " " << arr[3] << " ";
    finput << arr[4] << endl;
}
}