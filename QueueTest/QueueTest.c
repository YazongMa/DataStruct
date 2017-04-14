/*************************************************************************
	> File Name: QueueTest.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月14日 10:51:57
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "QueueTest.h"


/*初始化操作, 建立一个空队列 */
void InitQueue(QueueTestPtr* Q)
{
	*Q = (QueueTestPtr)calloc(1, sizeof(QueueTest));
}

/*若队列存在, 则销毁它 */
void DestroyQueue(QueueTestPtr* Q)
{
	while (QueueLength(*Q))
		PopFront(*Q);

	free(*Q);
	*Q = NULL;
}

/*清空队列 */
void ClearQueue(QueueTestPtr* Q)
{

}

/*判断队列是否为空, 空返回true, 否则false */
bool QueueEmpty(QueueTestPtr Q)
{
	return Q->count == 0;
}

/*若栈存在且非空, 返回队列头元素 */
int GetHead(QueueTestPtr Q)
{
	if (QueueEmpty(Q))
	{
		printf("Queue is empty");
		return 0;
	}

	return Q->front->data;
}

/*若队列存在, 将e插入队列并成为队尾元素 */
int PushBack(QueueTestPtr Q, DataType e)
{
	QueueNodePtr o = (QueueNodePtr)calloc(1, sizeof(QueueNode));
	o->data = e;
	Q->rear->next = o;
	Q->rear = o;
	Q->count++;

	return 0;
}

/*删除队头, 并返回其值 */
int PopFront(QueueTestPtr Q)
{
	if (QueueEmpty(Q))
	{
		printf("Queue is empty");
		return 0;
	}
	
	QueueNodePtr o = Q->front;
	int data = o->data;
	Q->front = o->next;
	Q->count--;

	free(o);
	o = NULL;

	return data;
}

/*返回栈S的元素个数 */
int QueueLength(QueueTestPtr Q)
{
	return Q->count;
}

