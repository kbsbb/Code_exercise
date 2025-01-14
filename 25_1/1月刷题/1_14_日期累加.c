//题目：日期累加
//链接：https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking
//描述：设计一个程序能计算一个日期加上若干天后是什么日期
//注释：
//思路：日期类的思路
//总结：秒了


#include <stdio.h>

//获取这个月份对应的最大天数，如果是闰年2月就是29天
int getMonthDay(int year, int month) {
    int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        monthDay[2] = 29;
    }
    return monthDay[month];
}

int main() {
    int num;    //循环次数
    int year, month, day, countDay;

    scanf("%d", &num);
    //循环num次输入
    for (int i = 0; i < num; i++) {
        scanf("%4d %d %d %d\n", &year, &month, &day, &countDay);
        //循环countDay次，每循环一次day++
        while (countDay != 0) {
            day++;
            //如果日期超过月份最大天数，月份+1，同时日期回到第1天，如果月份超过12，年份+1
            if (day > getMonthDay(year, month)) {
                month++;
                if (month == 13) {
                    year++;
                    month = 1;
                }
                day = 1;
            }
            countDay--;
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}