//
// Created by AdvanceQxj on 2020/7/30.
//

#ifndef INC_7_10_ACCOUNT_H
#define INC_7_10_ACCOUNT_H

#include "date.h"
#include "accumulator.h"
#include <string>
using namespace std;

class Account {             //账户类
private:
    string id;              //账户
    double balance;         //余额
    static double total;    //账户总金额

protected:
    //供派生类调用的构造函数,id 为账户
    Account(const Date &date, const string id);
    //记账,date 为日期,acount 为金额,desc 为说明
    void record(const Date &date, double amount, const string &desc);
    //报告错误信息
    void error(const string &msg) const ;

public:
    const string &getId() const { return id;}
    double getBalance() const { return balance;}
    static double getTotal() { return total;}
    //显示账户信息
    void show() const ;
};

class SavingAccount : public Account{       //储蓄账户类
private:
    Accumulator acc;                        //辅助计算利息的累加器
    double rate;                            //年利率

public:
    //构造函数
    SavingAccount(const Date &date, const string &id, double rate);
    double getRate() const { return rate;}
    //存钱
    void deposit(const Date &date, double amount, const string &desc);
    //取钱
    void withdraw(const Date &date, double amount, const string &desc);
    //结算年息,每年 1 月 1 日
    void settle(const Date &date);
};

class CreditAccount : public Account{       //信用账户类
private:
    Accumulator acc;                        //辅助计算利息的累加器
    double credit;                          //信用额度
    double rate;                            //欠款的日利率
    double fee;                             //年费
    double getDebt() const {                //获得额度
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }

public:
    CreditAccount(const Date &date, const string &id, double credit, double rate, double fee);
    double getCredit() const { return credit;}
    double getRate() const { return rate;}
    double getFee() const { return fee;}
    double getAvailableCredit() const {     //获得可用额度
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    void deposit(const Date &date, double amount, const string &desc);
    void withdraw(const Date &date, double amount, const string &desc);
    void settle(const Date &date);
    void show() const ;
};


#endif //INC_7_10_ACCOUNT_H
