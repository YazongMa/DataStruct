/*************************************************************************
	> File Name: main.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017Äê04ÔÂ13ÈÕ 16:51:57
 ************************************************************************/

#include <stdio.h>
#include <vld.h>
#include "Stack.h"

int main()
{
	StackTable* pStack = NULL;
	InitStack(&pStack);
	Push(pStack, 1);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));

	Push(pStack, 2);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));
	
	Pop(pStack);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));

	Push(pStack, 3);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));

	Push(pStack, 4);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));

	Pop(pStack);
	printf("top: %d, stack length: %d\n", GetTop(pStack), StackLength(pStack));

	DestroyStack(&pStack);

	return 0;
}
