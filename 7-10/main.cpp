#include <iostream>
#include "account.h"
using namespace std;

int main() {
    Date date(2008,11,1);

    //建立几个账户
    SavingAccount sa1(date,"s3755217",0.015);
    SavingAccount sa2(date,"02342342",0.015);
    CreditAccount ca(date,"c5392294",10000,0.0005,50);

    //11 月记账
    sa1.deposit(Date(2008,11,5),5000,"salary");
    ca.withdraw(Date(2008,11,15),2000,"buy a cell");
    sa2.deposit(Date(2008,11,25),10000,"sell stock 0323");

    //结算信用卡
    ca.settle(Date(2008,12,1));

    //12 月记账
    ca.deposit(Date(2008,12,1),2016,"repay the credit");
    sa1.deposit(Date(2008,12,5),5500,"salary");

    //结算所有账户
    sa1.settle(Date(2009,1,1));
    sa2.settle(Date(2009,1,1));
    ca.settle(Date(2009,1,1));

    //显示账户信息
    cout<<endl;
    sa1.show();
    cout<<endl;
    sa2.show();
    cout<<endl;
    ca.show();
    cout<<"Total: "<<Account::getTotal()<<endl;
    return 0;
}
