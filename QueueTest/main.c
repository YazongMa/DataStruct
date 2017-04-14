/*************************************************************************
	> File Name: main.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017Äê04ÔÂ14ÈÕ 16:51:57
 ************************************************************************/

#include <stdio.h>
#include <vld.h>
#include "QueueTest.h"

int main()
{
	QueueTestPtr pQueue = NULL;
	InitQueue(&pQueue);
	PushBack(pQueue, 1);

	PushBack(pQueue, 2);

	PushBack(pQueue, 3);

	PushBack(pQueue, 4);

	PushBack(pQueue, 5);

	DestroyQueue(&pQueue);

	return 0;
}
