//
// Created by AdvanceQxj on 2020/7/28.
//

#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;

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