#include <iostream>
#include "account.h"

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
