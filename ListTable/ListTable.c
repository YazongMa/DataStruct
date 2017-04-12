/*************************************************************************
	> File Name: ListTable.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月12日 16:28:57
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ListTable.h"

/*初始化操作, 建立一个空的线性表*/
void InitList(ListTable** L)
{
	*L = (ListTable*)calloc(1, sizeof(ListTable));
}


/*遍历链表*/
void PrintList(ListTable* L)
{
	ListTable* p = L;
	ListTable* q = L;
	while (p != NULL)
	{
		q = p;
		p = p->next;

		printf("%d ", q->data);
	}
	printf("\n");
}


/*判断线性表是否为空, 空返回true, 否则false*/
bool ListEmpty(ListTable* L)
{
	return L == NULL;
}


/*清空线性表*/
void ClearList(ListTable** L)
{
	ListTable* pHead = *L;
	ListTable* pCurN = NULL;
	while (pHead != NULL)
	{
		pCurN = pHead;
		pHead = pHead->next;

		free(pCurN);
		pCurN = NULL;
	}
	*L = NULL;
}


/*将线性表中第pos个位置的元素返回给e*/
int GetElem(ListTable* L, int pos, DataType* e)
{
	return 0;
}


/*在线性表L中查找元素e, 如果查找成功返回该元素序号, 否则返回0*/
int FindElem(ListTable* L, DataType e)
{
	return 0;
}


/*在线性表L的第pos个位置插入新元素e*/
int ListInsert(ListTable* L, int pos, DataType e)
{
	/*空链表报错, 并返回0*/
	if (L == NULL)
	{
		printf("List is empty, please InitList first !\n");
		return 0;
	}
	
	int len = ListLength(L);
	if (pos - len > 1 || pos <= 0)
	{
		printf("ListInsert error. List length is [%d], pos[%d] is out of bounds\n", len, pos);
		return 0;
	}

	int i = 1;
	ListTable* p = L;
	while (i < pos)
	{
		p = p->next;
		++i;
	}

	ListTable* o = (ListTable*)calloc(1, sizeof(ListTable));
	o->data = e;
	o->next = 0;

	ListTable* q = p->next;
	p->next = o;
	o->next = q;

	return i;
}


/*删除线性表L中第pos个位置的元素, 并用e返回其值*/
int ListDelete(ListTable* L, int pos, DataType* e)
{
	return 0;
}


/*返回线性表L的元素个数 */
int ListLength(ListTable* L)
{
	int length = 0;
	ListTable* p = L;
	ListTable* q = L;
	while (p != NULL)
	{
		q = p;
		p = p->next;

		++length;
	}

	return length;
}

