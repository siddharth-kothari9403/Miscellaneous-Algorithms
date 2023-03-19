#include <bits/stdc++.h>
using namespace std;

void conquer(int arr[], int const l, int const mid, int const r){
	int merged[r-l+1]; //this array stores the sorted merged array
	// to create this array, we will compare the elements of the sorted halves of the array passed as parameter
	// these halves are denoted by l, mid, r
	int p=0, i=l, j=mid+1;
	// p keeps track of the merged array indices, i,j are used to iterate over the halves

	while (i<=mid && j<=r){
	// breaks when one out of i,j reaches the respective ends
		if (arr[i]>=arr[j]){ //the element which is lesser is put in array, and the corresponding index tracker is moved ahead
			merged[p]=arr[j]; 
			j++; p++;
		}else{
			merged[p]=arr[i];
			i++; p++;
		}
	}
	
	// these 2 loops are to add the remaining elements to merged array
	// eg. if h=first half is 3,6,9,10 and second half is 2,5,8, then first loop breaks when 8 is added.
	// then these loops are useful to directly add the remaining elements
	while (i<=mid){
		merged[p]=arr[i];
		p++; i++;
	}

	while (j<=r){
		merged[p]=arr[j];
		p++; j++;
	}

	// loop to increment the values in the actual array
	for (int index1=l, index2=0; index2<p; index1++, index2++){
		arr[index1]=merged[index2];
	}

}

void divide(int arr[], int l, int r){
	if (l>=r){
		return;
	} //loop stops when l=r, i.e. only one element left
	int mid= l+ (r-l)/2; 
	divide(arr,l,mid); //recursive call on the left half
	divide(arr,mid+1,r); //recursive call on the right half
	conquer(arr,l,mid,r); //merge function to merge the sorted arrays
}

int main(){
	int n;
	cin>>n;
	int array[n];
	for (int i=0; i<n; i++){
		cin>>array[i];
	}

	divide(array,0,n-1);

	for (int i=0; i<n; i++){
		cout<<array[i]<<" ";
	} //print array

	cout<<endl;
	return 0;
}
