template <typename T>
void __quitSort3way(T arr[], int left, int right)
{
	if (left >= right){
		return;
	}

	swap(arr[left], arr[rand()%(right-left+1)+left]);
	int v = left;
	int l = left, r = right+1;

	int i = left+1;;

	while(1){
		if (i == r)
			break;
		if(arr[i] < arr[v]){
			swap(arr[i], arr[l+1]);
			i++; l++;
		} else if (arr[i] == arr[v]){
			i++;
		} else if (arr[i] > arr[v]){
			swap(arr[i], arr[r-1]);
			r--; 
		}
	}

	swap(arr[v], arr[l]);

	__quitSort3way(arr, left, l-1);
	__quitSort3way(arr, r, right);
}

template <typename T>
void quitSort(T arr[], int n) 
{
	srand(time(NULL));
	__quitSort3way(arr, 0, n-1);
}
