//题目：日期差值
//链接：https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=/activity/oj&qru=/ta/sju-kaoyan/question-ranking
//描述：有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//注释：注意多组输入的scanf要写!=EOF，否则会死循环,EOF是-1不是0
//思路：就是日期类的两个日期相减的方法，可以不用类实现
//总结：


#include <iostream>
using namespace std;

//创建一个时间类
class Date {
public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }
    int getMonthDay(int year, int month);
    bool operator>(Date& d)const;
    Date& operator++();

private:
    int _year;
    int _month;
    int _day;
};

//获取这个月份对应的天数，如果是闰年2月就是29天
int Date::getMonthDay(int year, int month) {
    int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        monthDay[2] = 29;
    }
    return monthDay[month];
}

//运算符重载
bool Date::operator>(Date& d)const {
    if (_year > d._year) {
        return true;
    }
    else if (_year == d._year && _month > d._month) {
        return true;
    }
    else if (_year == d._year && _month == d._month && _day > d._day) {
        return true;
    }
    else {
        return false;
    }

}

//前置++运算符重载
Date& Date::operator++() {
    _day += 1;
    if (_day > Date::getMonthDay(_year, _month)) {
        _day = 1;
        _month += 1;
        if (_month == 13) {
            _year += 1;
            _month = 1;
        }
    }
    return *this;
}

int main() {
    int year1, month1, day1, year2, month2, day2;
    //EOF是-1，如果不写!=EOF会进入死循环，while循环条件位0时结束，而不是-1
    while (scanf("%04d%02d%02d %04d%02d%02d", &year1, &month1, &day1, &year2, &month2, &day2) != EOF) { // 注意 while 处理多个 case

        Date d1(year1, month1, day1);
        Date d2(year2, month2, day2);
        //判断两个日期哪个大
        Date min = d1;
        Date max = d2;
        if (d1 > d2) {
            min = d2;
            max = d1;
        }

        //小日期++，知道和大日期相同
        int count = 0;
        while (max > min) {
            ++min;
            count++;
        }

        cout << (count + 1) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")