#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int size){
	int max=arr[0];
	for (int i=1;i<size;i++){
		if (arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void countSort(int arr[], int n, int max){
	int count[max+1];
	for (int i=0;i<=max+1;i++){
		count[i]=0;
	}

	for (int i=0;i<n;i++){
		count[arr[i]+1]++;
	}

	for (int i=2;i<=max+1;i++){
		count[i]+=count[i-1];
	}

	int b[n];
	for (int i=0;i<n;i++){
		b[count[arr[i]]]=arr[i];
		count[arr[i]]++;
	}

	for (int i=0;i<n;i++){
		arr[i]=b[i];
	}

}

void printArr(int arr[], int n){
	for (int i=0;i<n;i++){
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

	int m=max(arr,n);

	countSort(arr,n,m);
	printArr(arr,n);
	return 0;
}


