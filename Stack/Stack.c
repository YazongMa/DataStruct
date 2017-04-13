/*************************************************************************
	> File Name: StackTable.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月13日 16:51:57
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


/*初始化操作, 建立一个空的线性表 */
void InitStack(StackTable** S)
{
	*S = (StackTable*)calloc(1, sizeof(StackTable));
}

/*若栈存在, 则销毁它 */
void DestroyStack(StackTable** S)
{
	while (StackLength(*S))
		Pop(*S);

	free(*S);
	*S = NULL;
}

/*清空栈 */
void ClearStack(StackTable** S)
{
}

/*判断栈是否为空, 空返回true, 否则false */
bool StackEmpty(StackTable* S)
{
	return S->count == 0;
}

/*若栈存在且非空, 用e返回栈顶元素 */
int GetTop(StackTable* S)
{
	if (!S)	return 0;
	if (!S->top) return 0;
	
	return S->top->data;
}

/*若栈存在, 插入新元素e到栈中, 并成为栈顶元素 */
int Push(StackTable* S, DataType e)
{
	StackNodePtr o = (StackNode*)calloc(1, sizeof(StackNode));
	o->data = e;
	o->next = S->top;
	S->top = o;
	S->count++;

	return 0;
}

/*删除栈S中的栈顶元素, 并返回其值 */
int Pop(StackTable* S)
{	
	if (!S)	return 0;
	if (!S->top) return 0;

	StackNodePtr o = S->top;
	int data = o->data;
	S->top = o->next;
	S->count--;

	free(o);
	o = NULL;

	return data;
}

/*返回栈S的元素个数 */
int StackLength(StackTable* S)
{
	return S->count;
}
