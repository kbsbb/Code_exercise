//题目：化栈为队
//链接：https://leetcode.cn/problems/implement-queue-using-stacks-lcci/description/
//描述：实现一个MyQueue类，该类用两个栈来实现一个队列
//注释：
//思路：复制写好的栈代码，初始化两个栈，一个作为压栈，另一个作为出栈，出栈的时候如果出栈为空，把压栈全部数据push进出栈
//总结：简单的栈转队列问题，秒了



//创建栈

typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

//声明
//初始化
void StackInit(ST* ps);
//释放
void StackDestroy(ST* ps);
//入栈
void StackPuch(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//栈顶数据
STDataType StackTop(ST* ps);
//栈大小
STDataType StackSize(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);



//初始化
void StackInit(ST* ps)
{
    assert(ps);

    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

//释放
void StackDestroy(ST* ps)
{
    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;

}

//入栈
void StackPuch(ST* ps, STDataType x)
{
    assert(ps);
    //扩容
    if (ps->top == ps->capacity)
    {
        STDataType newcapacity = ps->capacity == 0 ? 4 : ps->top * 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;

}
//出栈
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    ps->top--;
}

//栈顶数据
STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    return ps->a[ps->top - 1];

}


//栈大小
STDataType StackSize(ST* ps)
{
    assert(ps);

    return ps->top;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
    assert(ps);

    return ps->top == 0;
}

//---------------------------------------
//以下是作答代码

typedef struct {
    ST PushStack;
    ST PopStack;
} MyQueue;

/** Initialize your data structure here. */
//函数声明
int myQueuePeek(MyQueue* obj);

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&obj->PushStack);
    StackInit(&obj->PopStack);
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPuch(&obj->PushStack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //复用myQueuePeek函数
    int ret = myQueuePeek(obj);
    StackPop(&obj->PopStack);
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    //如果PopStack栈为空的话就把PushStack栈的数据全部push到PopStack
    if (StackEmpty(&obj->PopStack)) {
        while (!StackEmpty(&obj->PushStack)) {
            StackPuch(&obj->PopStack, StackTop(&obj->PushStack));
            StackPop(&obj->PushStack);
        }
    }
    int ret = StackTop(&obj->PopStack);
    return ret;


}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    //两个栈都为空才返回真
    return StackEmpty(&obj->PushStack) && StackEmpty(&obj->PopStack);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->PushStack);
    StackDestroy(&obj->PopStack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/