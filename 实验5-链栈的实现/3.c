#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
struct LinkStack
{
    DataType data;
    struct LinkStack* next;
};
typedef struct LinkStack LinkStack;

LinkStack* InitStack()
{
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    s->next = NULL;
    return s;
}

int IsEmpty(LinkStack* s)
{
    return s->next == NULL;
}

int Push(LinkStack* s, DataType e)
{
    LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int Pop(LinkStack* s, DataType *e)
{
    if(IsEmpty(s))
    return 0;
    LinkStack* p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;
}

int GetTop(LinkStack* s, DataType *e)
{
    if(IsEmpty(s))
    return 0;
    *e = s->next->data;
    return 1;
}

int main()
{
    LinkStack* s = InitStack();
    char val;

    Push(s, 'A');
    Push(s, 'B');

    GetTop(s, &val);
    printf("栈顶：%c\n", val);

    Pop(s, &val);
    printf("出栈：%c\n", val);

    GetTop(s, &val);
    printf("栈顶：%c\n", val);

    return 0;
}
