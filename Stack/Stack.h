/*************************************************************************
	> File Name: Stack.h
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月13日 16:51:57
 ************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
typedef int DataType;

typedef struct StackNode
{
	DataType				data;
	struct StackNode*		next;
}StackNode, *StackNodePtr;

typedef struct StackTable
{
	StackNodePtr			top;
	int						count;
}StackTable;


/*初始化操作, 建立一个空的线性表 */
void InitStack(StackTable** S);

/*若栈存在, 则销毁它 */
void DestroyStack(StackTable** S);

/*清空栈 */
void ClearStack(StackTable** S);

/*判断栈是否为空, 空返回true, 否则false */
bool StackEmpty(StackTable* S);

/*若栈存在且非空, 返回栈顶元素 */
int GetTop(StackTable* S);

/*若栈存在, 插入新元素e到栈中, 并成为栈顶元素 */
int Push(StackTable* S, DataType e);

/*删除栈S中的栈顶元素, 并返回其值 */
int Pop(StackTable* S);

/*返回栈S的元素个数 */
int StackLength(StackTable* S);

#endif
