#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <cassert>

template <typename T>
int binarySearch(T arr[], int n, T target)
{
	int l = 0, r = n-1;
	while(l <= r) {
		//int mid = (l+r)/2;	有溢出风险
		int mid = l + (r-l)/2;
		if(arr[mid] == target) {
			return mid;
		} else if(target < arr[mid]) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return -1;
}

//在[l,r]中查找target
template <typename T>
int __binarySearchRecursion(T arr[], int l, int r, T target)
{	
	if(l > r)
		return -1;
    int mid  = l + (r-l)/2;
	if(arr[mid] == target) {
		return mid;
	} else if (target < arr[mid]) {
		return __binarySearchRecursion(arr, l, mid-1, target);
	} else {
		return __binarySearchRecursion(arr, mid+1, r, target);
	}
}

template <typename T>
int binarySearchRecursion(T arr[], int n, T target){
	return __binarySearchRecursion(arr, 0, n-1, target);
}




void testBinarySearch()
{
    int n = 1000;
	int *arr = new int[n];

	for(int i =0; i < n; i++){
		arr[i] = i;
	}
	for(int i = 0; i < 2*n; i++){
		int v = binarySearchRecursion(arr, n, i);
		if(i < n)
			assert(v==i);
        else 
			assert(v == -1);
	}

	delete [] arr;
}
#endif // BINARYSERACH_H