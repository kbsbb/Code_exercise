//题目：三合一
//链接：https://leetcode.cn/problems/three-in-one-lcci/
//描述：三合一。描述如何只用一个数组来实现三个栈。
//注释：把一个数组分成三个栈，函数的stackNum是三个栈的下标[0,1,2]
//思路：创建一个数组存放三个栈的数据，所以数组是三倍stackSize的大小，一个数组存放栈数据的个数
//总结：垃圾题目，示例不解释清楚，看别人题解半天才看懂题目要我干什么


typedef struct {
    // 记录三个栈中每个栈数据的个数
    int* top;
    // 实现栈的数组
    int* arr;
    // 记录栈的大小
    int stackSize;
} TripleInOne;

TripleInOne* tripleInOneCreate(int stackSize) {
    // 创建一个结构体，开辟一个空间存放数组
    TripleInOne* obj = (TripleInOne*)malloc(sizeof(TripleInOne));
    // 创建数组，数组大小为3倍的stackSize,数组分布：[栈0，栈1，栈2]
    obj->arr = (int*)malloc(3 * stackSize * sizeof(int));
    // 创建一个数组，记录三个栈存放数据的个数，默认都是0个
    obj->top = (int*)calloc(3, sizeof(int));
    // 记录栈的大小
    obj->stackSize = stackSize;
    return obj;
}

void tripleInOnePush(TripleInOne* obj, int stackNum, int value) {
    // 如果stackNum这个下标的栈满了，就什么都不做
    if (obj->top[stackNum] == obj->stackSize) {
        // 什么都不做
    }
    else {
        // 入栈
        // 在stackNum下标栈对应的地方入栈
        int index = obj->stackSize * stackNum + obj->top[stackNum];
        obj->arr[index] = value;
        // 记录 stackNum下标的栈的数据个数+1
        obj->top[stackNum]++;
    }
}

int tripleInOnePop(TripleInOne* obj, int stackNum) {
    // 如果栈为空就返回-1
    if (obj->top[stackNum] == 0) {
        return -1;
    }
    int index = obj->stackSize * stackNum + obj->top[stackNum] - 1;
    obj->top[stackNum]--;
    return obj->arr[index];
}

int tripleInOnePeek(TripleInOne* obj, int stackNum) {
    // 如果栈为空就返回-1
    if (obj->top[stackNum] == 0) {
        return -1;
    }
    int index = obj->stackSize * stackNum + obj->top[stackNum] - 1;
    return obj->arr[index];
}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum) {
    if (obj->top[stackNum] == 0) {
        return true;
    }
    return false;
}

void tripleInOneFree(TripleInOne* obj) {
    free(obj->top);
    free(obj->arr);
    obj->stackSize = 0;
}

/**
 * Your TripleInOne struct will be instantiated and called as such:
 * TripleInOne* obj = tripleInOneCreate(stackSize);
 * tripleInOnePush(obj, stackNum, value);

 * int param_2 = tripleInOnePop(obj, stackNum);

 * int param_3 = tripleInOnePeek(obj, stackNum);

 * bool param_4 = tripleInOneIsEmpty(obj, stackNum);

 * tripleInOneFree(obj);
*/