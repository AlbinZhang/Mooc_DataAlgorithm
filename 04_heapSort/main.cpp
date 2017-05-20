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
	for (i = 0; i < n; i++) {
		maxheap.insert(i);
	}

	for (i = n - 1; i >= 0; i--) {
		arr[i] = maxheap.pop();
	}
}

template <typename T>
void heapSort2(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	int i = 0;
	for (i = n - 1; i >= 0; i--) {
		arr[i] = maxheap.pop();
	}
}
template <typename T>
void __shiftDown(T arr[], int n, int index)
{
	while (index * 2+1 < n)
	{ //如果还有子节点
		int leftIndex = 2 * index + 1;
		int rightIndex = 2 * index + 2;
		if (rightIndex < n && arr[leftIndex] < arr[rightIndex]) {
			leftIndex = rightIndex;
		}
		if (arr[index] >= arr[leftIndex]) {
			break;
		}
		swap(arr[index], arr[leftIndex]);
		index = leftIndex;
	}
}

template <typename T>
void heapSort3(T arr[], int n)
{
	for(int i = (n-1)/2; i >=0; i--){
		__shiftDown(arr, n, i);
	}
	for(int i = n-1; i > 0; i--){
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

int main(int argc, char *argv[])
{
	int n = 1000000;
	int *arr1 = SortTextHelper::generateRangeArray(n, 0, n);
	int *arr2 = SortTextHelper::copyIntArray(arr1, n);
	int *arr3 = SortTextHelper::copyIntArray(arr1, n);
	int *arr4 = SortTextHelper::copyIntArray(arr1, n);
	int *arr5 = SortTextHelper::copyIntArray(arr1, n);

	cout << "number = " << n << endl;

	SortTextHelper::testSort("MergeSort 	", mergeSort, arr1, n);
	SortTextHelper::testSort("QuitSort3Way  ", quitSort, arr2, n);
	SortTextHelper::testSort("HeapSort1 	", heapSort1, arr3, n);
	SortTextHelper::testSort("HeapSort2 	", heapSort2, arr4, n);
	SortTextHelper::testSort("HeapSort3 	", heapSort3, arr5, n);

	delete [] arr1;
	delete [] arr2;
	delete [] arr3;
	delete [] arr4;
	delete [] arr5;

	getchar();
	return 0;
}