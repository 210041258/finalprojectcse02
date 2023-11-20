#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;

class customer : public user{
public:
    customer(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_);
    virtual ~customer();
    void customer_dashboard();
    void buy_ticket();
    void gui_1();
};
#endif
