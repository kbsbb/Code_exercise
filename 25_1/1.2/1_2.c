//题目：栈的最小值
//链接：https://leetcode.cn/problems/min-stack-lcci/description/
//描述：请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
//注释：
//思路：创建两个栈，一个存放数据，另一个存放最小值，每次入栈时，判断当前栈顶元素是否小于等于最小值栈顶元素，如果是，则将当前元素入栈，否则不操作
//总结：我写的方法时间复杂度不是O(1),太晚了没精力写了zzZ


typedef struct {
    // 栈数组
    int* _Stack;
    // 栈顶下标
    int _top;
    // 栈大小，支持动态扩容
    int _size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    // 默认给栈10个整形空间
    obj->_size = 10;
    obj->_Stack = (int*)malloc(sizeof(int) * (obj->_size));
    obj->_top = 0;

    return obj;
}

void minStackPush(MinStack* obj, int x) {
    // 如果栈内数据存满，按2倍扩容
    if (obj->_top == obj->_size) {
        int newsize = obj->_top * 2;
        // 注意realloc第二个参数是字节数，不是元素个数
        int* tmp = (int*)realloc(obj->_Stack, newsize * sizeof(int));
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        obj->_Stack = tmp;
        obj->_size = newsize;
    }

    // 入栈
    obj->_Stack[obj->_top] = x;
    obj->_top++;
}

void minStackPop(MinStack* obj) {
    // 如果栈为空打印信息
    if (obj->_top == 0) {
        printf("stack is empty\n");
    }
    else {
        obj->_top--;
    }
}

int minStackTop(MinStack* obj) {
    // 如果栈为空打印信息
    if (obj->_top == 0) {
        printf("stack is empty\n");
        return -1;
    }
    else {
        return obj->_Stack[obj->_top - 1];
    }
}

int minStackGetMin(MinStack* obj) {
    // 如果栈为空打印信息
    if (obj->_top == 0) {
        printf("stack is empty\n");
        return -1;
    }
    else {
        int min = obj->_Stack[0];
        // 用for循环遍历出栈中最小的一个数，返回
        for (int i = 0; i < obj->_top; i++) {
            if (obj->_Stack[i] < min) {
                min = obj->_Stack[i];
            }
        }
        return min;
    }
}

void minStackFree(MinStack* obj) {
    free(obj->_Stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/