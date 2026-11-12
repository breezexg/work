#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node
{
    DataType data;
    struct Node* next;
};
typedef struct Node Node;

Node* InitList()
{
    Node* h = (Node*)malloc(sizeof(Node));
    h->next = NULL;
    return h;
}

void HeadInsert(Node* h, DataType x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = h->next;
    h->next = p;
}

void TailInsert(Node* h, DataType x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    Node* r = h;
    while (r->next) r = r->next;
    r->next = p;
}

int IsEmpty(Node* h)
{
    return h->next == NULL;
}

int GetLen(Node* h)
{
    int n = 0;
    Node* p = h->next;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}

void Print(Node* h)
{
    Node* p = h->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node* L = InitList();
    TailInsert(L, 5);
    TailInsert(L, 7);
    TailInsert(L, 9);
    TailInsert(L, 11);
    printf("链表："); Print(L);
    printf("长度：%d\n", GetLen(L));
    printf("是否为空：%d\n", IsEmpty(L));

    HeadInsert(L, 3);
    printf("头插3后："); Print(L);
    system("pause");
    return 0;
}
