//
// Created by AdvanceQxj on 2020/7/30.
//

#ifndef INC_7_10_ACCUMULATOR_H
#define INC_7_10_ACCUMULATOR_H
#include "date.h"

class Accumulator { //将某个数值按日累加
private:
    Date lastDate;  //上次变更数值的日期
    double value;   //数值的当前值
    double sum;     //数值按日累加之和

public:
    //构造函数,date 为开始累加的日期,value 为初始值
    Accumulator(const Date &date, double value) :
        lastDate(date), value(value), sum(0) {}
    //获得日期 date 的累加结果
    double getSum(const Date &date) const {
        return sum + value * date.distance(lastDate);
    }
    //将数值变更为 value
    void change(const Date &date, double value){
        sum = getSum(date);
        lastDate = date;
        this->value = value;
    }
    //初始化,将日期变更为 date,数值变更为 value,累计值变更为 0
    void reset(const Date &date, double value){
        lastDate = date;
        this->value = value;
        sum = 0;
    }

};


#endif //INC_7_10_ACCUMULATOR_H
