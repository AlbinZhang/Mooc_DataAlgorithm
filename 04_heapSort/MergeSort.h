#ifndef MERGESORT_H
#define MERGESORT_H

#include <cassert>
#include <string.h>
#include <stdio.h>
#include <ctime>

using namespace std;

// 进行 [left, mid] [mid+1, right] 两个数组合并
template <typename T>
void __merge(T arr[], int left, int mid, int right)
{
	T *aux = new T[right-left+1];
	for (int i = left; i <= right; i++) {
		aux[i-left] = arr[i];
	}

	//开始进行合并 明确各个变量的含义
	//i aux left 数组的下标
	//j aux right 数组的下标
	//k 是i，j比较完之后，需要赋值给arr的下标
	int i = 0, j = mid-left+1;

	for(int k = left; k <= right; k++) {
		if(i > mid-left) {
			arr[k] = aux[j];
			j++;
		} else if (j > right-left) {
			arr[k] = aux[i];
			i++;
		} else if (aux[i] < aux[j]){
			arr[k] = aux[i];
			i++;
		} else {
			arr[k] = aux[j];
			j++;
		}
	}
	delete [] aux;
}

// 使用归并排序 a[left, right] 这个闭区间
template <typename T>
void __mergeSort(T arr[], int left, int right)
{
	if(left >= right)
		return;

	int mid = (right+left) / 2;
	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid+1, right);

	__merge(arr, left, mid, right);
}

template <typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n-1);
}

#endif //MERGESORT_H