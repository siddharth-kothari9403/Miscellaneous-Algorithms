#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l, int r){
	// pivot is first element as first element partitioning
	int pivot=arr[l], i=l+1, j=r;
	// i starts from left, j starts from right
	while (i<=j){
		// this loop breaks when either we reach the end of the array(i<=j) or we find an i such that a[i]>pivot
		while (i<=j && arr[i]<=pivot){
			i++; //if the elements are smaller, then they are in correct place, move on 
		}

		while (i<=j && arr[j]>pivot){ //same logics
			j--;
		}

		if (i<j){ //if we found an i such that a[i]>pivot and a j such that a[j]<=pivot, and i<j
		// that means that they need to be swapped, as we need the elements greater than the pivot at the end, and the ones less than pivot at the start
			swap(arr[i],arr[j]); i++; j--;
		}
	}
	// this loop continues till i>j, after which it breaks
	// now i is one ahead of the position of the pivot, do i-- and swap pivot and that position
	// it works as the element at index i-1 is also smaller, and it wont matter if we move it to start of the array, where pivot currently is
	i--; arr[l]=arr[i]; arr[i]=pivot; 
	// return the current position of pivot, so that it can be used later
	return i;

}
void randomQuickSort(int arr[], int l, int r){
	if (l<r){
		int p=(rand()%(r-l+1))+l; // to make the random number between l and r
		swap(arr[l],arr[p]); //swapping first element and current element, as the partition function that we have created is using first element partitioning
		int k=partition(arr,l,r); //calling partition function
		// recursive call on the 2 segments
		randomQuickSort(arr,l,k-1);
		randomQuickSort(arr,k+1,r);
	}
}
//array printing function
void printArray(int arr[], int l, int r){
	for (int i=l; i<=r; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;

	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}

	randomQuickSort(arr,0,n-1);
	printArray(arr,0,n-1);
	return 0;

}
