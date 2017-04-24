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
	InsertTree(&T, 62);
	InsertTree(&T, 58);
	InsertTree(&T, 88);
	InsertTree(&T, 47);
	InsertTree(&T, 73);
	InsertTree(&T, 99);
	InsertTree(&T, 35);
	InsertTree(&T, 51);
	InsertTree(&T, 93);
	InsertTree(&T, 37);
	DeleteNode(&T, 1);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	DestroyTree(&T);
	return 0;
}
