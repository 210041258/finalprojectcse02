#include "customer.h"
#include "user.h"
#include "tickets/tickets.h"
#define wait_and_cleen sleep(3);system("cls");

using namespace std;

customer::customer(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_)
    : user(_username, _password, _access, _admin_access, _co_cert_, _visa_cert_, _balance_)
{
}
//ready to run
void admin::gui_1()
{
    wait_and_cleen
    cout<<"\n1-Return to Dashboard\n2-Exit\nEnter the Number : "<<endl;
    int x;
    cin>>x;
    if(x==1)
    {
        user::customer_dashboard();
    }
    else
    {
        exit(0);
    }
}
// ready for run
void customer::buy_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1;
    if(!(t1.extract_info_id(id_))){cout << "ID Ticket Not Fouuned !! " << endl;}
    if(!(user::edit_access_balance(user::give_access_balance  - t1.give_access_price()))){
    cout << "Check the Balance !!" << endl;
    }
    if(!(user::save_user_operation(user::give_access_username,tickets::give_access_id,tickets::give_access_price)))
{
    cout << "Check your Account info and Ticket Info From the board !!" << endl;
    customer::gui_1();
}
    t1.print_info_id(id_);
    cout << "Your Avaliable Balanace : " << user::give_access_balance << endl;
    cout <<  "Your Operation is done !! " << endl;
    customer::gui_1();
}
// ready to run
void customer::return_ticket()
{
    int id_;
    cout << "Enter Id: " << endl;
    cin >> id_;
    tickets t1;
    if(!(t1.extract_info_id(id_))){cout << "ID Ticket Not Fouuned !! " << endl;}
    user::edit_access_balance(user::give_access_balance  + t1.give_access_price());
    user::return_user_operation(user::give_access_username,t1.give_access_id,t1.give_access_price);
    cout <<  "Your Operation is done !! " <<endl;
    customer::gui_1();
}

// ready to run
void customer::customer_dashboard()
{
    view_tickets();
    cout << "Welcome To User Panel " << endl;
    cout << "1 - Buy Ticket " << endl;
    cout << "2 - Return Ticket " << endl;
    cout << "3 - Exit Program " << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        customer::buy_ticket();
        break;
    case 2:
        customer::return_ticket();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid option. Please choose again." << endl;
        customer::customer_dashboard();
        break;
    }
}
void view_tickets(){
    ofstream output("tickets.txt");
    cout << "Ticket Id \t" <<  "" << "Ticket from " << "Ticket where " << "Ticket date to go"<< "Ticket date to return " << "Ticket price" ; 
    while(fileoutput >> arr[0] >> str[0] >> str[1] << str[2] << str[3] << arr[1] << arr[2] << arr[3])
    {
    cout << arr[0] << "\t" << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << arr[1] << endl;
    }
}
