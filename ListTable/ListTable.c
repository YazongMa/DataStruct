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
	printf("List Elements: ");
	if (L->data == 0)
	{
		printf("Empty list!!!\n");
		return;
	}

	for (int pos = 0; pos < L->data; ++pos)
	{
		//头结点不打印
		p = p->next;
		printf("%d ", p->data);
	}

	printf("\n");
}


/*反向遍历链表*/
void __rPrintList(ListTable* L)
{
	if (L->next == NULL)	
		return;

	__rPrintList(L->next);
	printf("%d ", L->next->data);
}

void rPrintList(ListTable* L)
{
	printf("Reverse List : ");
	__rPrintList(L);
	printf("\n");
}


/*判断线性表是否为空, 空返回true, 否则false*/
bool ListEmpty(ListTable* L)
{
	return L->data == 0;
}


/*清空线性表*/
void ClearList(ListTable** L)
{
	ListTable* p = *L;
	ListTable* q = NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;
}


/*将线性表中第pos个位置的元素返回给e*/
int GetElem(ListTable* L, int pos, DataType* e)
{
	/*空链表报错, 并返回0*/
	if (L == NULL)
	{
		printf("List is empty, please InitList first !\n");
		return 0;
	}

	int len = ListLength(L);
	if (pos > len || pos <= 0)
	{
		printf("GetElem error. List length is [%d], pos[%d] is out of bounds\n", len, pos);
		return 0;
	}

	int cur = 0;
	ListTable* p = L;
	while (cur < pos)
	{
		p = p->next;
		++cur;
	}

	if (!p || cur != pos)
		return 0;

	*e = p->data;

	return 0;
}


/*在线性表L中查找元素e, 如果查找成功返回该元素序号, 否则返回0*/
int FindElem(ListTable* L, DataType e)
{
	int cur = 1;
	int len = ListLength(L);
	ListTable* p = L;
	while (cur <= len)
	{
		p = p->next;
		if (p->data == e)
		{
			return cur;
		}
		
		++cur;
	}
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

	int cur = 1;
	ListTable* p = L;
	while (p && cur < pos)
	{
		p = p->next;
		++cur;
	}

	if (!p || cur > pos)
		return 0;

	ListTable* o = (ListTable*)calloc(1, sizeof(ListTable));
	o->data = e;
	o->next = p->next;
	p->next = o;

	//头结点数据域表示链表长度
	++L->data;

	return cur;
}



/*返回线性表L的元素个数 */
int ListLength(ListTable* L)
{
	return L->data;
}




/*删除线性表L中第pos个位置的元素, 并用e返回其值 */
int ListDelete(ListTable* L, int pos, DataType* e)
{
	int cur = 1;
	int len = ListLength(L);
	ListTable* p = L;
	while (cur <= len)
	{
		ListTable* q = p;
		p = p->next;
		if (cur == pos)
		{
			q->next = p->next;

			free(p);
			p = NULL;

			--L->data;
		}

		++cur;
	}

	return 0;
}