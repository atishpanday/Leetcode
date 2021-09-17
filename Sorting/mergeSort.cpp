
#include<iostream>

using namespace std;

void merge(int* Arr, int left, int mid, int right){
	int k=0;
	int A[mid-left+1];
	int B[right-mid];
	for(int i=left; i<=mid; i++){
		A[k] = Arr[i];
		k++;
	}
	k = 0;
	for(int i=mid+1; i<=right; i++){
		B[k] = Arr[i];
		k++;
	}
	k = left;
	int i=0, j=0;
	while(i < (mid-left+1) && j < (right-mid)){
		if(A[i] < B[j]){
			Arr[k] = A[i];
			i++;
		}
		else{
			Arr[k] = B[j];
			j++;
		}
		k++;
	}
	while(i < (mid-left+1)){
		Arr[k] = A[i];
		i++;
		k++;
	}
	while(j < (right-mid)){
		Arr[k] = B[j];
		j++;
		k++;
	}
}

void merge_sort(int* A, int left, int right){
	int mid;
	// if(left == right || left == right + 1 || left == right - 1){
	// 	if(A[left] > A[right]){
	// 		int temp = A[left];
	// 		A[left] = A[right];
	// 		A[right] = temp;
	// 	}
	// 	return;
	// }

	if(left < right){
		mid = (left + right) / 2;
		merge_sort(A, left, mid); 
		merge_sort(A, mid+1, right);
		merge(A, left, mid, right);
		return;
	}
}

int main(){
	int Arr[] = {2, 3, 5, 1, 0, 7};
	int size = sizeof(Arr)/sizeof(int);
	cout << size << endl;
	merge_sort(Arr, 0, size-1);
	for(int i=0; i<size; i++){
		cout << Arr[i];
	}
	cout << endl;
	return 0;
}

// 2, 3, 5, 1, 0, 7
// 2, 3, 5		1, 0, 7
// 2, 3		5		1, 0 		7
// [2, 3]	[5]		[0, 1]		[7]
// []