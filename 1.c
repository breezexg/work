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

int main()
{
    SetConsoleOutputCP(CP_UTF8);  
    struct Stack st;
    int val;
    InitStack(&st, 10);

    Push(&st, 100);
    GetTop(&st, &val);
    printf("栈顶：%d\n", val);
    Pop(&st, &val);
    printf("出栈：%d\n", val);

    free(st.elements);
    return 0;
}
