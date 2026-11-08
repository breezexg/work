#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int DataType;
struct Stack
{
    int top;
    int maxsize;
    DataType* elements;
};

//1) 初始化空栈
void InitStack(struct Stack *s, int max)
{
    s->maxsize = max;
    s->top = -1;
    s->elements = (DataType*)malloc(sizeof(DataType) * max);
}

//2) 判断栈空
int IsEmpty(struct Stack *s)
{
    return s->top == -1;
}

//3) 判断栈满
int IsFull(struct Stack *s)
{
    return s->top == s->maxsize - 1;
}

//4) 入栈
int Push(struct Stack *s, DataType x)
{
    if (IsFull(s))
        return 0;
    s->top++;
    s->elements[s->top] = x;
    return 1;
}

//5) 出栈
int Pop(struct Stack *s, DataType *x)
{
    if (IsEmpty(s))
        return 0;
    *x = s->elements[s->top];
    s->top--;
    return 1;
}

//6) 获取栈顶
int GetTop(struct Stack *s, DataType *x)
{
    if (IsEmpty(s))
        return 0;
    *x = s->elements[s->top];
    return 1;
}

// 十进制转base进制（2 ≤ base ≤9）
void DecToBase(int number, int base)
{
    struct Stack st;
    int temp;
    InitStack(&st, 100);  //开足够大的栈空间

    // 特殊情况：数字是0
    if(number == 0)
    {
        printf("0");
        free(st.elements);
        return;
    }

    // 除基取余，余数入栈
    while(number > 0)
    {
        temp = number % base;
        Push(&st, temp);
        number = number / base;
    }

    // 出栈，逆序打印结果
    while(!IsEmpty(&st))
    {
        Pop(&st, &temp);
        printf("%d", temp);
    }
    free(st.elements);
}

int main()
{
    int num, b;
    SetConsoleOutputCP(CP_UTF8);  // 设置控制台输出编码为 UTF-8，防止中文乱码
    printf("输入十进制数：");
    scanf("%d", &num);
    printf("输入目标进制(2~9)：");
    scanf("%d", &b);

    if(b < 2 || b > 9)
    {
        printf("进制只能是2~9！");
        return 0;
    }
    printf("转换结果：");
    DecToBase(num, b);
    printf("\n");
    return 0;
}
