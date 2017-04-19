/*************************************************************************
	> File Name: BinaryTree.c
	> Author: YazongMa
	> Mail: mayazong@126.com 
	> Created Time: 2017年04月19日 10:51:57
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


/*初始化操作, 建立一个二叉数 */
void InitTree(TreeNodePtr* T)
{
	*T = NULL;
}

/*若二叉树存在, 则销毁它 */
void DestroyTree(TreeNodePtr* T)
{
	if (*T == NULL)
		return;

	if ((*T)->lchild != NULL)
		DestroyTree(&(*T)->lchild);
	if ((*T)->rchild != NULL)
		DestroyTree(&(*T)->rchild);
	
	free(*T);
	*T = NULL;
}


/*

*/
TreeNodePtr FindElem(TreeNodePtr T, DataType e)
{
	if (T->data == e)
		return T;
	
	if (T->data < e)
	{
		if (T->rchild == NULL)
			return T;
		return FindElem(T->rchild, e);
	}
	
	if (T->data > e)
	{
		if (T->lchild == NULL)
			return T;
		return FindElem(T->lchild, e);
	}

	return NULL;
}

/*若二叉树不存在, 创建二叉树并把e赋给根结点，否则平衡插入值e */
void InsertTree(TreeNodePtr* T, DataType e)
{
	TreeNodePtr o = (TreeNodePtr)calloc(1, sizeof(TreeNode));
	o->data = e;

	if (*T == NULL)
	{
		*T = o;
		return;
	}

	TreeNodePtr root = NULL;
	if ((*T)->data < e)
	{
		if ((*T)->rchild == NULL)
		{
			(*T)->rchild = o;
			return;
		}
		root = FindElem((*T)->rchild, e);
	}
	else if ((*T)->data > e)
	{
		if ((*T)->lchild == NULL)
		{
			(*T)->lchild = o;
			return;
		}
		root = FindElem((*T)->lchild, e);
	}
	else
	{
		printf("元素已存在, 直接返回\n", e);
		return;
	}

	if (root == NULL)
		return;

	if (root->data < e)
	{
		root->rchild = o;
	}
	else
	{
		root->lchild = o;
	}
}

/*判断二叉树是否为空, 空返回true, 否则false */
bool TreeEmpty(TreeNodePtr T)
{
	if (T == NULL)
		return true;
	return false;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
DataType TreeDepth(TreeNodePtr T)
{
	if (T == NULL)
		return 0;
	int l = 0, r = 0;
	if (T->lchild)
		l = TreeDepth(T->lchild);
	if (T->rchild)
		r = TreeDepth(T->rchild);

	return l > r ? l + 1 : r + 1;
}

/* 操作结果: 返回T所指结点的值 */
DataType Value(TreeNodePtr T)
{
	return T->data;
}

/* 给T所指结点赋值为value */
void Assign(TreeNodePtr T, DataType value)
{
	T->data = value;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(TreeNodePtr T)
{
	if (!T) return;
	printf("%d ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(TreeNodePtr T)
{
	if (!T) return;
	InOrderTraverse(T->lchild);
	printf("%d ", T->data);
	InOrderTraverse(T->rchild);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(TreeNodePtr T)
{
	if (!T) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%d ", T->data);
}