/*************************************************************************
	> File Name: ListTable.h
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月12日 16:28:57
 ************************************************************************/

#ifndef __LISTTABLE_H__
#define __LISTTABLE_H__

#include <stdbool.h>
typedef int DataType;

typedef struct ListTable
{
	DataType				data;
	struct ListTable*		next;
}ListTable;


/*初始化操作, 建立一个空的线性表*/
void InitList(ListTable** L);

/*遍历链表*/
void PrintList(ListTable* L);

/*判断线性表是否为空, 空返回true, 否则false*/
bool ListEmpty(ListTable* L);

/*清空线性表*/
void ClearList(ListTable** L);

/*将线性表中第pos个位置的元素返回给e*/
int GetElem(ListTable* L, int pos, DataType* e);

/*在线性表L中查找元素e, 如果查找成功返回该元素序号, 否则返回0*/
int FindElem(ListTable* L, DataType e);

/*在线性表L的第pos个位置插入新元素e*/
int ListInsert(ListTable* L, int pos, DataType e);

/*返回线性表L的元素个数 */
int ListLength(ListTable* L);

/*删除线性表L中第pos个位置的元素, 并用e返回其值 */
int ListDelete(ListTable* L, int pos, DataType* e);

#endif
