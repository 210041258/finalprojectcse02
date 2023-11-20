#ifndef USER_H
#define USER_H
using namespace std;
#pragma once
#include <string>

class user
{
public:
    user(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_);
    virtual ~user();
    ///
    string give_access_username();
    string give_access_password();
    int give_access_access();
    int give_access_admin_access();
    int give_access_co_cert();
    int give_access_visa_cert();
    int give_access_balance();
    ///
    void edit_access_username(string _user);
    void edit_access_password(string password);
    void edit_access_access(int _access);
    void edit_access_admin_access(int _admin_access);
    void edit_access_co_cert(int _co_cert__);
    void edit_access_visa_cert(int _visa_cert_);
    void edit_access_balance(int _balance_);
    ///
    /*function we must edit the function to let it have the update for that data*/
    void save_user_direct();
    int extract_info_username(string username_);//ifsr
    int delete_username(string username_);
    int print_info_username(string username_);
    int search_username(string username_);//ifsr
    int print_user_operation(string username_);
    void save_user_operation(string username_,int id_,int value);
    int return_user_operation(string username_,int id_,int value);
private:
    string username;
    string password;
    int access;
    int admin_access;
    int co_cert;
    int visa_cert;
    int balance;
};

#endif // USER_H
