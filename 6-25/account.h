//
// Created by AdvanceQxj on 2020/7/29.
//

#ifndef INC_6_25_ACCOUNT_H
#define INC_6_25_ACCOUNT_H

#include <string>
#include "date.h"
using namespace std;
//账户储蓄类
class SavingAccount {
private:
    string id;                                                          //账户名
    double balance;                                                     //余额
    double rate;                                                        //年利率
    Date lastDate;                                                      //上次变更余额的日期
    double accumulation;                                                //余额按日累积之和
    static double total;                                                //所有账户的总金额
    void record(const Date &date, double amount, const string desc);    //记账,date 日期,amount 金额,desc说明
    void error(const string &msg) const ;                               //报告错误信息
    double accumulate(const Date &date) const {                         //获得到指定日期位置的存款金额按日累积之和
        return accumulation + balance * date.distance(lastDate);
    }

public:
    SavingAccount(const Date &date, const string &id, double rate);
    const string &getId() const { return id;}
    double getBalance() const { return balance;}
    double getRate() const { return rate;}
    static double getTotal() { return total;}
    //存钱
    void deposit(const Date &date, double amount, const string desc);
    //取钱
    void withdraw(const Date &date, double amount, const string desc);
    //结算利息,每年 1 月 1 日调用
    void settle(const Date &date);
    //显示账户信息
    void show() const ;
};


#endif //INC_6_25_ACCOUNT_H
