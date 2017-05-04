/*************************************************************************
> File Name: main.c
> Author: YazongMa
> Mail: mayazong@126.com
> Created Time: 2017年05月04日 10:26:57
************************************************************************/
#include <stdio.h>
#include <vld.h>
#include <string.h>


void DataSwap(int* array, size_t size, int l, int r)
{
	if (!array || l >= size || r >= size || l == r)
		return;

	int tmp = array[r];
	array[r] = array[l];
	array[l] = tmp;
}


void PrintArray(int* array, size_t size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}


/*冒泡排序*/
void BubbleSort(int* array, size_t size)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (int j = size - 1; j >= i; --j)
		{
			if (array[j] > array[j + 1])
			{
				DataSwap(array, size, j, j + 1);
			}
		}
	}
}


/*选择排序*/
void SelectSort(int* array, size_t size)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		int min_Index = i;
		int min_Data = array[i];
		for (int j = i + 1; j < size; ++j)
		{
			if (min_Data > array[j])
			{
				min_Index = j;
				min_Data = array[j];
			}
		}
		DataSwap(array, size, i, min_Index);
	}
}


/*快速排序*/
int partition(int* array, int size, int l, int r)
{
	int pivot = l;

	while (l < r)
	{
		while (pivot < r && array[pivot] < array[r])
			--r;
		DataSwap(array, size, pivot, r);
		pivot = r;

		while (l < pivot && array[l] < array[pivot])
			++l;
		DataSwap(array, size, pivot, l);
		pivot = l;
	}

}

void QSort(int* array, int size, int l, int r)
{
	if (l >= r)
		return;

	int pivot = partition(array, size, l, r);
	QSort(array, size, l, pivot - 1);
	QSort(array, size, pivot + 1, r);
}

void QuickSort(int* array, size_t size)
{
	QSort(array, size, 0, size - 1);
}




int main()
{
	int array[10] = {3, 9, 5, 2, 7, 0, 8, 4, 1, 6};
	
	//BubbleSort(array, 10);
	
	//SelectSort(array, 10);

	//QuickSort(array, 10);
	
	PrintArray(array, 10);
}