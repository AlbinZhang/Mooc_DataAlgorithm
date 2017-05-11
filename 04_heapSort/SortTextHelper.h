#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <cassert>
#include <iomanip>

using namespace std;

namespace SortTextHelper {
	// 生成有n个元素的随机数组，元素的范围[rangeL, rangeR]
	int *generateRangeArray(int n, int rangeL, int rangeR) {

		assert(rangeL <= rangeR);

		int * arr = new int[n];

		srand(time(NULL));
		for(int i=0; i < n; i++){
			arr[i] = rand() % (rangeR-rangeL+1) + rangeL;
		}
		return arr;
	}

	template <typename T>
		void printArray(T arr[], int n) {
			for(int i =0 ; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}

	template <typename T>
		bool isSorted(T arr[], int n) {
			for(int i = 0; i < n-1; i++) {
				if( arr[i+1] < arr[i] ) {
					return false;
				}
			}
			return true;
		}

	template <typename T>
		void testSort(const char *sortName,void (*sort)(T arr[], int ), T arr[], int n) {

			clock_t startTime = clock();
			sort(arr, n);
			clock_t endTime = clock();

			assert(isSorted(arr,n));

			cout << sortName << ":" << setiosflags(ios::fixed) << double(endTime-startTime)  / CLOCKS_PER_SEC << "s" << endl;
		}

		int * copyIntArray(int a[], int n) {
			int *arr = new int[n];
			copy(a, a+n, arr);
			return arr;
		}
}

#endif //SORTTESTHELPER_H
