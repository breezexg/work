#include <stdio.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void InitList(SqList *L)
{
    L->length = 0;
}

void CreateList(SqList *L, int n)
{
    if (n < 0 || n > MAXSIZE)
    {
        printf("创建失败，数量超出范围！\n");
        return;
    }
    printf("请输入%d个整数：", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L->data[i]);
    }
    L->length = n;
}

int IsEmpty(SqList *L)
{
    return L->length == 0;
}

int GetLength(SqList *L)
{
    return L->length;
}

void PrintList(SqList *L)
{
    if (IsEmpty(L))
    {
        printf("顺序表为空！\n");
        return;
    }
    printf("顺序表元素：");
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int GetElem(SqList *L, int position, int *e)
{
    if (position < 1 || position > L->length)
    {
        printf("位置非法！\n");
        return 0;
    }
    *e = L->data[position - 1];
    return 1;
}

int SeqSearch(SqList *L, int value)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == value)
            return i + 1;
    }
    return 0;
}

int BinarySearch(SqList *L, int value)
{
    int low = 0, high = L->length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (L->data[mid] == value)
            return mid + 1;
        else if (L->data[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int ListInsert(SqList *L, int position, int x)
{
    if (position < 1 || position > L->length + 1 || L->length >= MAXSIZE)
    {
        printf("插入位置错误或者表满！\n");
        return 0;
    }
    for (int i = L->length - 1; i >= position - 1; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[position - 1] = x;
    L->length++;
    return 1;
}

int ListDeletePos(SqList *L, int position)
{
    if (position < 1 || position > L->length)
    {
        printf("删除位置非法！\n");
        return 0;
    }
    for (int i = position; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}

void ListDeleteValue(SqList *L, int value)
{
    int j = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] != value)
        {
            L->data[j++] = L->data[i];
        }
    }
    L->length = j;
}

int main()
{
    SqList L;
    int e, pos, val, n, x;
    InitList(&L);
    printf("请输入创建顺序表元素个数：");
    scanf("%d", &n);
    CreateList(&L, n);
    PrintList(&L);

    printf("%s\n", IsEmpty(&L) ? "是空表" : "非空");
    printf("顺序表长度:%d\n", GetLength(&L));

    printf("请输入要获取的位置：");
    scanf("%d", &pos);
    if (GetElem(&L, pos, &e))
        printf("该位置元素=%d\n", e);

    printf("输入要查找的值（顺序查找）：");
    scanf("%d", &val);
    int res = SeqSearch(&L, val);
    if (res) printf("顺序查找：元素在第%d位\n", res);
    else printf("顺序查找：未找到\n");

    printf("输入要查找的值：");
    scanf("%d", &val);
    res = BinarySearch(&L, val);
    if (res) printf("二分查找：元素在第%d位\n", res);
    else printf("二分查找：未找到\n");

    printf("输入插入位置、插入的值：");
    scanf("%d %d", &pos, &x);
    ListInsert(&L, pos, x);
    printf("插入后：");
    PrintList(&L);

    printf("输入要删除的位置：");
    scanf("%d", &pos);
    ListDeletePos(&L, pos);
    printf("删除该位置后：");
    PrintList(&L);

    printf("输入要删除的元素值（删除所有相同元素）：");
    scanf("%d", &val);
    ListDeleteValue(&L, val);
    printf("删除所有等于%d元素后：", val);
    PrintList(&L);

    return 0;
}
