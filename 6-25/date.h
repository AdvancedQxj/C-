//
// Created by AdvanceQxj on 2020/7/29.
//

#ifndef INC_6_25_DATE_H
#define INC_6_25_DATE_H


class Date {
private:
    int year;                               //年
    int month;                              //月
    int day;                                //日
    int totalDays;                          //该日期是从公元元年1 月 1 日开始的第几天

public:
    Date(int year, int month, int day);     //用年、月、日构造函数
    int getYear() const { return year;}
    int getMonth() const { return month;}
    int getDay() const { return day;}
    int getMaxDay() const ;                 //获得当月多少天
    bool isLeapYear() const {               //是否闰年
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
    void show() const ;                     //显示当前日期
    int distance(const Date &date) const {  //计算两个日期之间相差多少天
        return totalDays - date.totalDays;
    }
};


#endif //INC_6_25_DATE_H
