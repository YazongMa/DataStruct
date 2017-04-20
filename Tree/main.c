/*************************************************************************
	> File Name: main.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017Äê04ÔÂ19ÈÕ 16:51:57
 ************************************************************************/

#include <stdio.h>
#include <vld.h>
#include <string.h>

#include "BinaryTree.h"

int main()
{
	TreeNodePtr T;
	InitTree(&T);
	InsertTree(&T, 5);
	InsertTree(&T, 3);
	InsertTree(&T, 7);
	InsertTree(&T, 4);
	InsertTree(&T, 6);
	InsertTree(&T, 1);
	InsertTree(&T, 8);
	InsertTree(&T, 2);
	InsertTree(&T, 9);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	DestroyTree(&T);
	return 0;
}
