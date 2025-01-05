#pragma once
#include <iostream>
using namespace std;

class Date {
public:

    //获得月份对应天数
    int GetMonthDay(int year, int month)const;

    //构造函数，使用缺省参数
    Date(int year = 0, int month = 1, int day = 1);

    //拷贝构造函数,加const防止修改原对象
    Date(const Date& d);
    //------------------------------------------------------------------------
    //运算符重载

    //判断小于 d1<d2
    //d1.operator<(&d1, d2)
    bool operator<(const Date& d)const;

    //判断等于 d1==d2
    //d1.operator==(&d1, d2)
    bool operator==(const Date& d)const;

    //d1<=d2
    bool operator<=(const Date& d)const;

    //d1>d2
    bool operator>(const Date& d)const;

    //d1>=d2
    bool operator>=(const Date& d)const;

    //d1!=d2
    bool operator!=(const Date& d)const;

    //d1 + 10
    //因为返回的是局部变量，函数调用完会销毁，所以返回值不能是引用
    Date operator+(int d)const;

    //d1 += 10
    Date& operator+=(int d);

    //d1 - 10
    Date operator-(int d)const;

    //d1 -= 10
    Date& operator-=(int d);

    //++d1=> d1.operator++(&d1)
    Date& operator++();

    //d1++=> d1.operator++(&d1, 0)
    //C++ 语言规定，后置自增运算符++的重载函数必须接受一个int类型
    //的参数，这是为了区分前置自增和后置自增。这个int参数在实际调用
    //后置自增运算符时并不传递实际的值，它只是作为一个占位符
    Date operator++(int);

    //--d1
    Date& operator--();

    //d1--
    Date operator--(int);

    //d1-d2
    int  operator-(const Date& d)const;

    //------------------------------------------------------------------------
    //打印日期，如果日期非法，打印失败
    void Print()const;

private:
    int _year;
    int _month;
    int _day;
    //标记表示是否合法,1表示合法，0表示非法
    int _flag = 0;
};