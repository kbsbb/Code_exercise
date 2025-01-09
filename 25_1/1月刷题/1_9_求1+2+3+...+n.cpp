//题目：求1+2+3+...+n
//链接：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//描述：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//注释：
//思路：使用构造函数和static修饰变量特性，调用n次构造函数，每次i++，累加到sum中，最后返回sum。
//总结：


#include <iostream>
using namespace std;

class _Solution {
public:
    _Solution() {
        _sum += _i;
        _i++;
    }

    static int getSum() {
        return _sum;
    }

    static void Init() {
        _i = 1;
        _sum = 0;
    }
private:
    static int _i;
    static int _sum;
};

//定义静态变量
int _Solution::_i = 1;
int _Solution::_sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        //注意为了防止多次调用，每次调用前都要初始化需要
        _Solution::Init();

        //下面两个方法都可以，会调用n次构造函数
        //_Solution* p = new _Solution[n];d
        _Solution a[n];

        return _Solution::getSum();
    }
};

int main() {
    Solution s1;
    cout << s1.Sum_Solution(5);
    return 0;
}
