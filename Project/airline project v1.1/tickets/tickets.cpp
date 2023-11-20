#include "tickets.h"
#include<fstream>
#include<cstdio>

using namespace std;

tickets::tickets(int _id,string _from,string _where,string _date_go,string _date_ret,int _price,int _t_visa_req,int _t_cov_req)
{
    id=_id;
    from=_from;
    where=_where;
    date_go=_date_go;
    date_ret=_date_ret;
    price=_price;
    t_visa_req=_t_visa_req;
    t_cov_req=_t_visa_req;
    save_ticket_direct();
}

/// ready to run
int tickets::give_access_id()
{
    return tickets::id;
}
string tickets::give_access_from()
{
    return tickets::from;
}
string tickets::give_access_where()
{
    return tickets::where;
}
string tickets::give_access_date_go()
{
    return tickets::date_go;
}
string tickets::give_access_date_ret()
{
    return tickets::date_ret;
}
int tickets::give_access_price()
{
    return tickets::price;
}
int tickets::give_access_t_visa_req()
{
    return tickets::t_visa_req;
}
int tickets::give_access_t_cov_req()
{
    return tickets::t_cov_req;
}

void tickets::edit_access_id(int _id)
{
    id=_id;
}
void tickets::edit_access_form(string from_)
{
    from=from_;
}
void tickets::edit_access_where(string where_)
{
    where=where_;
}
void tickets::edit_access_date_go(string go_)
{
    date_go=go_;
}
void tickets::edit_access_date_ret(string return_)
{
    date_ret=return_;
}
void tickets::edit_access_price(int price_)
{
    price=price_;
}
void tickets::edit_access_t_visa_req(int visa_)
{
    t_visa_req=visa_;
}
void tickets::edit_access_t_cov_req(int cov_)
{
    t_cov_req=cov_;
}
/// ready to run

int tickets::save_ticket_direct()
{
    ofstream finput("tickets.txt",ios::app);
    finput << tickets::give_access_id << tickets::give_access_from;
    finput << tickets::give_access_where << tickets::give_access_date_go;
    finput << tickets::give_access_date_ret << tickets::give_access_price;
    finput << tickets::give_access_t_visa_req << tickets::give_access_t_cov_req;
    return 1;
}

int tickets::search_id(int id_)
{
    int id;
    char str[1024];
    ifstream fileoutput("tickets.txt");
    while(!(fileoutput.eof()))
    {
        fileoutput.getline(str,1024);
        sscanf(str,"%d ",&id);
        if(id_ == id)
        {
            return 1;
        }
    }
    return 0;
}

int tickets::print_info_id(int id_)
{
    int intarr[4];
    string strarr[4];
    char str[1024];
    ifstream fileoutput("tickets.txt");
    if(!(fileoutput.open())){
        cerr << "Error  Occurs !! " <<endl;
        return 0;
    }
    while(fileoutput >> intarr[0] >> strarr[0] >> strarr[1] >> strarr[2] >> strarr[3] >> intarr[1] >> intarr[2] >> intarr[3])
    {
        if(id_ == intarr[0])
        {
            cout << "Ticket Information : " <<endl;
            cout << "The Ticket Id : " << intarr[0] <<endl;
            cout << "The Ticket From : " << strarr[0] <<endl;
            cout << "To : " << strarr[1] <<endl;
            cout << "date to start the flight : " << strarr[2] <<endl;
            cout << "date to return the flight : " << strarr[3] <<endl;
            cout << "the price of flight : " << strarr[1] <<endl;
            cout << "the Visa-Contry requirment of flight : " << strarr[2] <<endl;
            cout << "the Covid-19 requirment of flight : " << strarr[3] <<endl;
            return 1;
        }
    }
    return 0;
}

tickets tickets::extract_info_id(int id_)

{
    tickets t;
    int intarr[4];
    string strarr[4];
    char str[1024];
    ifstream fileoutput("tickets.txt");
    while(!(fileoutput.eof()))
    {
        fileoutput.getline(str,1024);
        sscanf(str,"%d %s %s %s %s %d %d %d",&intarr[0],strarr[0],strarr[1],strarr[2],strarr[3],&intarr[1],&intarr[2],&intarr[3]);
        if(id_ == id)
        {
            t.edit_access_id(intarr[0]);
            t.edit_access_form(strarr[0]);
            t.edit_access_where(strarr[1]);
            t.edit_access_date_go(strarr[2]);
            t.edit_access_date_ret(strarr[3]);
            t.edit_access_price(intarr[1]);
            t.edit_access_t_visa_req(intarr[2]);
            t.edit_access_t_cov_req(intarr[3]);
            return t;
        }
    }
}
int tickets::delete_ticket(int id_)
{
    int id;
    char str[1024];
    char str2[1024];
    ifstream fileoutput("tickets.txt");
    ofstream fileinput("tickets_new.txt",ios::app);
    while(!(fileoutput.eof()))
    {
        fileoutput.getline(str,1024);
        sscanf(str,"%d ",&id);
        if(id_ != id)
        {
            str2=str;
            fileinput.write(str2,1024);
        }
    }
    fileoutput.close();
    fileinput.close();
    ifstream fileoutput("tickets_new.txt");
    ofstream fileinput("tickets.txt",ios::app);
    while(!(fileoutput.eof()))
    {
        fileoutput.getline(str,1024);
        sscanf(str,"%d ",&id);
        if(id_ != id)
        {
            str2=str;
            fileinput.write(str2,1024);
        }
    }
    fileoutput.close();
    fileinput.close();
    return 1;
}
