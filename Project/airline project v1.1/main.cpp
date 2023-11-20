#include <iostream>
#include <cstdlib>
#include "user/customer/customer.h"
#include "tickets/tickets.h"
#include "user/admin/admin.h"
#include "user/user.h"
#include <unistd.h>
#include <windows.h>
#define wait_and_cleen sleep(3);system("cls");
#include<fstream>
using namespace std;
void start_program();
void login();
void sgin_up();
int main()
{
    start_program();
    return 0;
}

void start_program()
{
    int x;
    cout << "Welcome to our system for airlines tickets" << endl;
    cout << "\n 1-Login \n 2-Sgin up \n 3-Exit\n" << endl;
    cout << "Enter the number :" << endl;
    cin >> x;
    switch(x)
    {
    case 1 :
        login();
        break;
    case 2:
        sgin_up();
        break;
    case 3:
        exit(1);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        start_program();
        wait_and_cleen
        break;
    }
}
void login()
{
    string username,user_temp;
    string password,pass_temp;
    int arr[5];
    cout << "Enter Username :" << endl;
    getline(cin,username);
    cout << "Enter Password :" << endl;
    getline(cin,password);
    // user data
    ifstream user_data("db/user.txt",ios::app);

    while(!(user_data >> user_temp >> pass_temp >> arr[0] >> arr[1]))
    {
        if((username==user_temp)&&(password==pass_temp))
        {
            if((arr[0])&&(!arr[1]))
            {
                wait_and_cleen
                customer u1(user_temp,pass_temp,1,0,1,1,100000);
                cout << "Sign in Done ..!" <<endl;
                wait_and_cleen
                u1.customer_dashboard();
            }
            else if((arr[1])&&(arr[0]))
            {
                wait_and_cleen
                cout << "\nSgin as Customer press 1 \n as admin press 2 \n";
                int aa;
                cin>>aa;
if(aa==1){
                    customer u1(user_temp,pass_temp,1,0,1,1,100000);
                    cout << "Sign in Done ..!" <<endl;
                    wait_and_cleen
                    u1.customer_dashboard();
}     else if(aa==2){
                    admin u2(user_temp,pass_temp,1,1,1,1,100000);
                    cout << "Sign in Done {ADMIN} ..!" <<endl;
                    wait_and_cleen
                    u2.admin_dashboard();
}                else{
                    cout << "Invalid option. Please choose again." << endl;
                    wait_and_cleen
                    login();
                }
            }
        }

    }
    if(!((username==user_temp)&&(password==pass_temp)))
    {
        cout << "error input info of the user "<<endl;
        wait_and_cleen
    }
}

void sgin_up()
{
    string pass_temp,user_temp;
    cout << "Enter Username :" << endl;
    getline(cin,user_temp);
    cout << "Enter Password :" << endl;
    getline(cin,pass_temp);
    customer c1(user_temp,pass_temp,1,0,1,1,100000);
    cout << "Sign UP Done ..!" <<endl;
    wait_and_cleen
    c1.customer_dashboard();
}
