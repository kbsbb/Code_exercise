//题目：计算日期到天数转换
//链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//描述：输入描述：在一行上输入三个整数a,b,c(1900≦a≦2200)a, b, c(1900≦a≦2200)，分别代表年、月、日。保证输入的日期是合法的。
        //输出描述：输出一个整数，代表输入的日期是这一年的第几天。
//注释：
//思路：
//总结：简单题


#include <iostream>
using namespace std;

class Date {
  public:
    Date(int year = 0, int month = 0, int day = 0)
        : _year(year), _month(month), _day(day)
    {}
    int countDate();

  private:
    int _year;
    int _month;
    int _day;
};

int Date::countDate() {
    //定义每月对应天数的数组，如果是闰年2月为29天
    int dayVal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;
    if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
        dayVal[2] = 29;
    }
    _month--;
    //循环算出前几个月的天数，最后加上当月的天数
    while (_month > 0) {
        count += dayVal[_month];
        _month--;
    }
    return count + _day;
}

int main() {
    int year, month, day;
    while (cin >> year >> month >> day) {
        Date d1(year, month, day);
        int countDay = d1.countDate();
        cout << countDay << endl;
    }
    return 0;
}
