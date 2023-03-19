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

void countSort(int arr[], int n, int exp){
	int max=9;
	int count[11]={0};

	for (int i=0;i<n;i++){
		count[(arr[i]/exp)%10+1]++;
	}

	for (int i=2;i<=max+1;i++){
		count[i]+=count[i-1];
	}

	int b[n];
	for (int i=0;i<n;i++){
		b[count[(arr[i]/exp)%10]]=arr[i];
		count[(arr[i]/exp)%10]++;
	}

	for (int i=0;i<n;i++){
		arr[i]=b[i];
	}

}

void radixSort(int arr[], int n){
	int m=max(arr,n);
	for (int exp=1; (m/exp)>0; exp*=10){
		countSort(arr,n,exp);
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

	radixSort(arr,n);
	printArr(arr,n);
	return 0;

}
