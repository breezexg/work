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

int BracketMatch(char *str)
{
    LinkStack* s = InitStack();
    int i = 0;
    char top;
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            Push(s,str[i]);
        }
        else if(str[i]==')')
        {
            if(GetTop(s,&top)&&top=='(')
            Pop(s,&top);
            else
            return 0;
        }
        else if(str[i]==']')
        {
            if(GetTop(s,&top)&&top=='[')
            Pop(s,&top);
            else
            return 0;
        }
        else if(str[i]=='}')
        {
            if(GetTop(s,&top)&&top=='{')
            Pop(s,&top);
            else
            return 0;
        }
        i++;
    }
    if(IsEmpty(s))
    return 1;
    return 0;
}

int main()
{
    char str[100];
    scanf("%s",str);
    if(BracketMatch(str))
    printf("括号匹配正确");
    else
    printf("括号匹配错误");
    return 0;
}
