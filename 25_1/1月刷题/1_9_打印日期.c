//题目：打印日期
//链接：https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
//描述：给出年分m和一年中的第n天，算出第n天是几月几号
//注释：
//思路：
//总结：秒了


#include <iostream>
#include <linux/limits.h>
using namespace std;
int getMonthDay(int year, int month) {
    int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        monthDay[2] = 29;
    }
    return monthDay[month];
}

int main() {
    int year, countDay;
    while (cin >> year >> countDay) {
        countDay--;
        int month = 1;
        int day = 1;
        while (countDay != 0) {
            day++;
            countDay--;

            if (day > getMonthDay(year, month)) {
                month++;
                if (month == 13) {
                    year++;
                    month = 1;
                }
                day = 1;
            }
        }
        printf("%4d-%02d-%02d\n", year, month, day);

    }

    return 0;
}
// 64 位输出请用 printf("%lld")