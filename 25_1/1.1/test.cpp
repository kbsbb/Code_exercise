#include <iostream>
using namespace std;

class Date {
public:

    //获得月份对应天数
    int GetMonthDay(int year, int month) {
        static int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            return 29;
        }
        return monthDay[month];
    }

    //构造函数，使用缺省参数
    Date(int year = 0, int month = 1, int day = 1) {
        //判断日期是否合法
        if (year >= 0
            && month >= 1 && month <= 12
            && day >= 1 && day <= GetMonthDay(year, month)) {
            _year = year;
            _month = month;
            _day = day;
            _flag = 1;
        }
        else {
            _flag = 0;
            cout << "构造失败：日期非法" << endl;
        }
    }

    //拷贝构造函数,加const防止修改原对象
    Date(const Date& d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        _flag = d._flag;

    }
    //------------------------------------------------------------------------
    //运算符重载

    //判断小于 d1<d2
    //d1.operator<(&d1, d2)
    bool operator<(const Date& d) {
        if (_year < d._year) {
            return true;
        }
        else if (_year == d._year && _month < d._month) {
            return true;
        }
        else if (_year == d._year && _month == d._month && _day < d._day) {
            return true;
        }
        else
            return false;
    }

    //判断等于 d1==d2
    //d1.operator==(&d1, d2)
    bool operator==(const Date& d) {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    //d1<=d2
    bool operator<=(const Date& d) {
        return *this < d || *this == d;
    }

    //d1>d2
    bool operator>(const Date& d) {
        return !(*this <= d);
    }

    //d1>=d2
    bool operator>=(const Date& d) {
        return !(*this < d);
    }

    //d1!=d2
    bool operator!=(const Date& d) {
        return !(*this == d);
    }

    //d1 + 10
    //因为返回的是局部变量，函数调用完会销毁，所以返回值不能是引用
    Date operator+(int d) {
        if (d < 0) {
            return *this - (-d);
        }
        Date ret(*this);
        ret._day += d;
        while (ret._day > GetMonthDay(ret._year, ret._month)) {
            ret._day -= GetMonthDay(ret._year, ret._month);
            ret._month++;
            if (ret._month == 13) {
                ret._month = 1;
                ret._year++;
            }
        }
        return ret;
    }

    //d1 += 10
    Date& operator+=(int d) {
        if (d < 0) {
            return *this -= -d;
        }
        _day += d;
        while (_day > GetMonthDay(_year, _month)) {
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month == 13) {
                _month = 1;
                _year++;
            }
        }
        return *this;
    }

    //d1 - 10
    Date operator-(int d) {
        Date ret(*this);
        //复用operator-=
        ret -= d;
        return ret;
    }

    //d1 -= 10
    Date& operator-=(int d) {
        if (d < 0) {
            return *this += -d;
        }
        _day -= d;
        while (_day < 1) {
            _month--;
            if (_month == 0) {
                _month = 12;
                _year--;
            }
            _day += GetMonthDay(_year, _month);
        }
        return *this;
    }

    //++d1=> d1.operator++(&d1)
    Date& operator++() {
        *this += 1;
        return *this;	//返回加之后的值
    }

    //d1++=> d1.operator++(&d1, 0)
    //C++ 语言规定，后置自增运算符++的重载函数必须接受一个int类型
    //的参数，这是为了区分前置自增和后置自增。这个int参数在实际调用
    //后置自增运算符时并不传递实际的值，它只是作为一个占位符
    Date operator++(int) {	//为了构成重载
        Date temp(*this);
        *this += 1;
        return temp;	//返回加之前的值
    }

    //--d1
    Date& operator--() {
        *this -= 1;
        return *this;
    }

    //d1--
    Date operator--(int) {
        Date temp(*this);
        *this -= 1;
        return temp;
    }

    //------------------------------------------------------------------------
    //打印日期，如果日期非法，打印失败
    void Print() {
        if (_flag == 1)
            cout << _year << "年" << _month << "月" << _day << "日" << endl;
        else
            cout << "打印失败：日期非法" << endl;

    }

private:
    int _year;
    int _month;
    int _day;
    //标记表示是否合法,1表示合法，0表示非法
    int _flag = 0;
};





int main() {
    //Date d1;
    Date d2(2025, 2, 10);
    Date d3(d2);

    Date d4(2025, 2, 28);

    //d1.Print();
    //d3.Print();
    /*d2.Print();
    d4.Print();*/

    //测试运算符重载
    /*cout << (d2 < d4)<<endl;
    cout << (d2 == d3) << endl;
    cout << (d2 <= d4) << endl;
    cout << (d2 > d4) << endl;
    cout << (d2 >= d4) << endl;
    cout << (d2 != d4) << endl;*/

    //测试+/+=/-/-=运算符
    d2.Print();
    Date d5 = d2;
    d5.Print();
    cout << "------------------------" << endl;
    //测试+/+=
    /*d2.Print();
    d2 += 100;
    d2.Print();*/
    //测试-/-=
    d5 = d2 - 11;
    d2.Print();
    d5.Print();
    d2 -= 10;
    d2.Print();
    cout << "------------------------" << endl;
    //测试++/--运算符
    d2.Print();

    d2--.Print();
    (--d2).Print();


    return 0;
}