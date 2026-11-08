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


void InitStack(struct Stack *s, int max)
{
    s->maxsize = max;
    s->top = -1;
    s->elements = (DataType*)malloc(sizeof(DataType) * max);
}

int IsEmpty(struct Stack *s)
{
    return s->top == -1;
}

int IsFull(struct Stack *s)
{
    return s->top == s->maxsize - 1;
}

int Push(struct Stack *s, DataType x)
{
    if (IsFull(s))
        return 0;
    s->top++;
    s->elements[s->top] = x;
    return 1;
}

int Pop(struct Stack *s, DataType *x)
{
    if (IsEmpty(s))
        return 0;
    *x = s->elements[s->top];
    s->top--;
    return 1;
}

int GetTop(struct Stack *s, DataType *x)
{
    if (IsEmpty(s))
        return 0;
    *x = s->elements[s->top];
    return 1;
}

void DecToBase(int number, int base)
{
    struct Stack st;
    int temp;
    InitStack(&st, 100);  

    if(number == 0)
    {
        printf("0");
        free(st.elements);
        return;
    }

    while(number > 0)
    {
        temp = number % base;
        Push(&st, temp);
        number = number / base;
    }

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
    SetConsoleOutputCP(CP_UTF8);  
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
