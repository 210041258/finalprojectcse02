#include "admin.h"
#include <unistd.h>
#include "tickets/tickets.h"
#include "user/user.h"
#define wait_and_cleen sleep(3);system("cls");
// ready to run
void admin::gui_1()
{
    wait_and_cleen
    cout<<"\n1-Return to Dashboard\n2-Exit\nEnter the Number : "<<endl;
    int x;
    cin>>x;
    if(x==1)
    {
        admin::admin_dashboard();
    }
    else
    {
        exit(0);
    }
}

admin::admin(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_):user(_username, _password, _access, _admin_access, _co_cert_, _visa_cert_, _balance_)
 {}

// ready to run
void admin::admin_dashboard()
{
    cout << "Welcome to admin pannel" << endl;
    cout << "1 - add ticket " << endl;
    cout << "2 - edit ticket " <<endl;
    cout << "3 - delete ticket " << endl;;
    cout << "4 - spacifc ticket info "<< endl;
    cout << "5 - block user " << endl;
    cout << "6 - Track Operation spacifc user " << endl;
    cout << "7 - spacifc user info " << endl;
    cout << "8 - Logout \n" << endl;
    cout << "Enter the number : " << endl;
    int x;
    cin >> x;
    switch(x)
    {
    case 1:
        admin::add_ticket();
        break;
    case 2:
        admin::edit_ticket();
        break;
    case 3:
        admin::delete_ticket();
        break;
    case 4:
        admin::view_info_ticket();
        break;
    case 5 :
        admin::block_user();
        break;
    case 6 :
        admin::track_op_user();
        break;
    case 7 :
        admin::view_info_user();
        break;
    case 8:
        exit(0);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        customer::admin_dashboard();
        break;
    }
}
// ready to run
void admin::block_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    getline(cin,username);
    user u1;
    if(!(u1.extract_info_username(username)))
    {
        cout << "Username Not Founed !!" << endl;
        admin::gui_1();
    }
    u1.edit_access_access(0);
    admin::gui_1();
}
// ready to run
void admin::track_op_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    getline(cin,username);
    cin.ignore();
    if(!(print_username_operation(username)))
    {
        cout << "User name Not Founded !!" << endl;
    }
    cout << "Extracted Info done !!" << endl;
    admin::gui_1();
}
// ready to run
void admin::view_info_user()
{
    wait_and_cleen
    string username;
    cout << "Enter the username :" << endl;
    getline(cin,username);
    if(!(print_info_username(username)))
    {
        cout << "User name not founed " << endl;
    }
    cout << "Printing info done !!" << endl;
    admin::gui_1();
}
// ready to run
void admin::add_ticket()
{
    wait_and_cleen
    string temp_str[4];
    int temp_int[4];
    cout << "Provide all the information here : \n" << endl;
    cout << "Enter Id : " << endl;
    cin >> temp_int[0];
    cout << "Enter from : " << endl;
    cin >> temp_str[0];
    cout << "Enter Id : " << endl;
    cin >> temp_str[1];
    cout << "Enter from : " << endl;
    cin >> temp_str[2];
    cout << "Enter Id : " << endl;
    cin >> temp_str[3];
    cout << "Enter price : " << endl;
    cin >> temp_int[1];
    cout << "Enter  visa requirment : " << endl;
    cin >> temp_int[2];
    cout << "Enter corona requirment : " << endl;
    cin >> temp_int[3];
    tickets t1(temp_int[0],temp_str[0],temp_str[1],temp_str[2],temp_str[3],temp_int[1],temp_int[2],temp_int[3]);
}
// ready to run
void admin::edit_ticket()
{
    wait_and_cleen
    cout << "Enter Your Id: " << endl;
    int x;
    cin>>x;
    tickets t2;
    if(!(t2.search_id(x)))
    {
        cout << "Your id not Founed !!" <<endl;
        admin::gui_1();
    }
    t2 = t2.extract_info_id(x);
    cout << " which data you want to edit ? " << endl;
    cout << " 1- Id \n 2- Where \n 3- From \n 4-date go \n 5-date return \n 6-price \n 7-visa requriment \n 8-covied requriment \n" << endl;
    cout << "Enter Number : \n" << endl;
    cin >> x;
    string s;
    int a;
    switch (x)
    {
    case 1:
        cin >>a;
        t2.edit_access_id(a);
        break;
    case 2:
        cin>>s;
        t2.edit_access_where(s);
        break;
    case 3:
        cin >> s;
        t2.edit_access_form(s);
        break;
    case 4:
        cin>>s;
        t2.edit_access_date_go(s);
        break;
    case 5:
        cin >>s;
        t2.edit_access_date_ret(s);
        break;
    case 6:
        cin>>a;
        t2.edit_access_price(a);
        break;
    case 7:
        cin >> a;
        t2.edit_access_t_visa_req(a);
        break;
    case 8:
        cin >> a;
        t2.edit_access_t_cov_req(a);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        customer::admin_dashboard();
        break;
    }
    cout << "Ticket Updated !!" << endl;
    t2.~tickets();
    wait_and_cleen
    admin::gui_1();
}
// ready to run
void admin::delete_ticket()
{
    wait_and_cleen
    cout << "Enter Your Id: " << endl;
    int x;
    cin>>x;
    tickets t1;
    if(!(t1.delete_ticket(x)))
    {
        cout << "CHECK THE ID OF THE TICKET !!" <<endl;
        wait_and_cleen
        admin::admin_dashboard();
    }
    t1.print_info_id(x);
    t1.~tickets();
    cout << "Deleted Done !! "<< endl;
    wait_and_cleen
    admin::gui_1();
}
// ready to run
void admin::view_info_ticket()
{
    wait_and_cleen
    int x;
    cout << "Enter the ID :" << endl;
    cin >> x;
    tickets t1 ;
    if(!(t1.print_info_id(x)))
    {
        cout << "Check the Id !!" << endl;
    }
    cout << "Ticket Info Extracted !!"<<endl;
    admin::gui_1();
    t1.~tickets();
}




