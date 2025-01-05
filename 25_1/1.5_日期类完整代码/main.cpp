#include "Test.h"

void testDate() {
    //Date d1;
    Date d2(2024, 2, 10);
    Date d3(d2);

    Date d4(2024, 3, 28);

    //d1.Print();
    //d3.Print();
    /*d2.Print();
    d4.Print();*/

    //测试运算符重载
    cout << (d2 < d4) << endl;
    cout << (d2 == d3) << endl;
    cout << (d2 <= d4) << endl;
    cout << (d2 > d4) << endl;
    cout << (d2 >= d4) << endl;
    cout << (d2 != d4) << endl;

    //测试+/+=/-/-=运算符
    d2.Print();
    Date d5 = d2;
    d5.Print();
    //cout<<"------------------------"<<endl;
    //测试+/+=
    d2.Print();
    d2 += 100;
    d2.Print();
    //测试-/-=
    d5 = d2 - 11;
    d2.Print();
    d5.Print();
    d2 -= 10;
    d2.Print();
    //cout << "------------------------" << endl;
    //测试++/--运算符
    d2.Print();

    d2--.Print();
    (--d2).Print();

    cout << d4 - d2 << endl;
}

void sub(const Date& d1, const Date& d2) {
    cout << d1 - d2 << endl;
}


int main() {
    //testDate();

    Date d3(2025, 1, 5);
    Date d4(d3);
    sub(d3, d4);
    Date d5(2025, 3, 22);
    cout << &d3 << endl;
    cout << &d4 << endl;
    cout << d5 - d3 << endl;



    return 0;
}