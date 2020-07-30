//
// Created by AdvanceQxj on 2020/7/30.
//

#include "date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace {
    //仅在当前文件下有效
    //存储平年中的某个月 1 日之前有多少天,为便于 getMaxDay 函数的实现,该数组多出一项
    const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day){
    if (day < 0 || day > getMaxDay()){
        cout<<"Invalid date: ";
        show();
        cout<<endl;
        exit(1);
    }
    int years = year - 1;
    totalDays = years * 365 + year / 4 - year / 100 + year / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2) totalDays++;
}

int Date::getMaxDay() const {
    if (isLeapYear() && month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

void Date::show() const {
    cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay();
}
