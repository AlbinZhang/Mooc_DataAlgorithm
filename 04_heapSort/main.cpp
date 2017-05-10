#include <iostream>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#include "SortTextHelper.h"
#include "Maxheap.h"
#include "MergeSort.h"
#include "QuitSort.h"

using namespace std;

template <typename T>
void heapSort1(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	int i = 0;
	for (i = 0; i < n; i++){
		maxheap.insert(i);
	}

	for (i = n - 1; i >= 0; i--)
	{
		arr[i] = maxheap.pop();
	}
}

template <typename T>
void heapSort2(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	int i = 0;
	for (i = n - 1; i >= 0; i--)
	{
		arr[i] = maxheap.pop();
	}
}

int main(int argc, char *argv[])
{
	int n = 1000000;
	int *arr1 = SortTextHelper::generateRangeArray(n, 0, n);
	int *arr2 = SortTextHelper::copyIntArray(arr1, n);
	int *arr3 = SortTextHelper::copyIntArray(arr1, n);
	int *arr4 = SortTextHelper::copyIntArray(arr1, n);

	cout << "number = " << n << endl;
	
	SortTextHelper::testSort("MergeSort 	", mergeSort, arr1, n);
	SortTextHelper::testSort("QuitSort3Way  ", quitSort, arr2, n);
	SortTextHelper::testSort("HeapSort1 	", heapSort1, arr3, n);
	SortTextHelper::testSort("HeapSort2 	", heapSort2, arr4, n);

	return 0;
}