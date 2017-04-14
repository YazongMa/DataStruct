/*************************************************************************
	> File Name: QueueTest.h
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月14日 10:51:57
 ************************************************************************/

#ifndef __QUEUETEST_H__
#define __QUEUETEST_H__

#include <stdbool.h>
typedef int DataType;

typedef struct QueueNode
{
	DataType				data;
	struct QueueNode*		next;
}QueueNode, *QueueNodePtr;

typedef struct QueueTest
{
	QueueNodePtr			front;
	QueueNodePtr			rear;
	int						count;
}QueueTest, *QueueTestPtr;


/*初始化操作, 建立一个空队列 */
void InitQueue(QueueTestPtr* Q);

/*若队列存在, 则销毁它 */
void DestroyQueue(QueueTestPtr* Q);

/*清空队列 */
void ClearQueue(QueueTestPtr* Q);

/*判断队列是否为空, 空返回true, 否则false */
bool QueueEmpty(QueueTestPtr Q);

/*若栈存在且非空, 返回队列头元素 */
int GetHead(QueueTestPtr Q);

/*若队列存在, 将e插入队列并成为队尾元素 */
int PushBack(QueueTestPtr Q, DataType e);

/*删除队头, 并返回其值 */
int PopFront(QueueTestPtr Q);

/*返回栈S的元素个数 */
int QueueLength(QueueTestPtr Q);

#endif
