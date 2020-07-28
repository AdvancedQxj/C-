#include <iostream>
#include <cmath>
using namespace std;

//储蓄账户类
class SavingAccount{
private:
    int id;                                 //账户
    double balance;                         //余额
    double rate;                            //年利率
    int lastDate;                           //上次变更余额时间
    double accumulation;                    //余额按日累加之和
    void record(int date, double amount);   //记账,date 为日期,amount 为金额,desc 为说明
    double accumulate(int date) const {     //计算到期后的余额
        return accumulation + balance * (date - lastDate);
    }

public:
    SavingAccount(int date, int id, double rate);   //构造函数
    int getId(){
        return id;
    }
    int getBalance(){
        return balance;
    }
    int getRate(){
        return rate;
    }
    void deposit(int date, double amount);          //存钱
    void withdraw(int date, double amount);         //取钱
    void settle(int date);                          //结算利息
    void show();                                    //显示账户信息
};

SavingAccount::SavingAccount(int date, int id, double rate) :
    id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
    cout<<date<<"\t#"<<id<<" is created"<<endl;
}
void SavingAccount::record(int date, double amount) {
    accumulation = accumulate(date);
    lastDate = date;
    //floor 函数向下取整
    amount = floor(amount * 100 + 0.5) / 100;       //保留小数点后两位
    balance += amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
void SavingAccount::deposit(int date, double amount) {
    record(date, amount);
}
void SavingAccount::withdraw(int date, double amount) {
    if (amount > getBalance())
        cout<<"Error: not enough money!"<<endl;
    else
        record(date, -amount);
}
void SavingAccount::settle(int date) {
    double interest = accumulate(date) * rate / 365;
    if (interest != 0)
        record(date, interest);
    accumulation = 0;
}
void SavingAccount::show() {
    cout<<"#"<<id<<"\tBalance: "<<balance<<endl;
}
//主程序
int main() {
    //建立账户
    SavingAccount sa0(1, 21325302, 0.015);
    SavingAccount sa1(1, 58320212, 0.015);
    //记账
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);
    sa1.withdraw(60, 4000);
    //开户后第 90 天结算利息
    sa0.settle(90);
    sa1.settle(90);
    //显示账户信息
    sa0.show();
    sa1.show();
    return 0;
}
