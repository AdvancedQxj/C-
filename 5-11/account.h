//
// Created by AdvanceQxj on 2020/7/28.
//

#ifndef INC_5_11_ACCOUNT_H
#define INC_5_11_ACCOUNT_H

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


#endif //INC_5_11_ACCOUNT_H
