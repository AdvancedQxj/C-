//
// Created by AdvanceQxj on 2020/7/29.
//

#include "account.h"
#include <cmath>
#include <iostream>
using namespace std;

double SavingAccount::total = 0;

SavingAccount::SavingAccount(const Date &date, const string &id, double rate)
        : lastDate(date), id(id), balance(0), rate(rate), accumulation(0){
    date.show();
    cout<<"\t#"<<id<<" is created"<<endl;
}

void SavingAccount::record(const Date &date, double amount, const string desc) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}
void SavingAccount::error(const string &msg) const {
    cout<<"Error(#"<<id<<"):"<<msg<<endl;
}

void SavingAccount::deposit(const Date &date, double amount, const string desc) {
    record(date, amount ,desc);
}
void SavingAccount::withdraw(const Date &date, double amount, const string desc) {
    if (amount > getBalance())
        error("not enough money!");
    else
        record(date, -amount, desc);
}
void SavingAccount::settle(const Date &date) {
    double interest = accumulate(date) * rate / date.distance(Date(date.getYear()-1,1,1));
    if (interest != 0)
        record(date, interest, "interest");
    accumulation = 0;
}
void SavingAccount::show() const {
    cout<<id<<"\tBalance: "<<balance;
}