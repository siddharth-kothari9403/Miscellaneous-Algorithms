#include <bits/stdc++.h>
using namespace std;

int prefix_sum(vector<int> prefix,vector<int>a,int ss,int se,int l,int r,int i)
{
     if(l<=ss && r>=se)
    {
        return prefix[i];
    }
    else if(se<l|| ss>r)
    {
        return 0; // we are returning zero so that during calculation it does not affect it.
    }
    int mid = (ss+se)/2;
    int m1 = prefix_sum(prefix,a,ss,mid,l,r,2*i+1);
    //cout<<m1<<endl;
    int m2 = prefix_sum(prefix,a,mid+1,se,l,r,2*i+2);
    return m1+m2;
}

int querySum(vector<int> prefix, vector<int> a, int l, int r){
    int i=1;

    while (i<a.size()){
        i*=2;
    }
    return prefix_sum(prefix, a, 0, i-1, l, r, 0);
}

vector<int> createSumTree(vector<int> arr){
    int i=1;

    while (i<arr.size()){
        i*=2;
    }

    int k=i;
    vector<int> tree(2*k-1);
    i=2*k-2;
    while (i>=arr.size()+k-1){
        tree[i]=0;
        i--;
    }

    for (int i=0; i<arr.size(); i++){
        //cout<<arr[i]<<endl;
        tree[i+k-1]=arr[i];
    }

    for (int i=k-2; i>-1; i--){
        tree[i]=tree[2*i+1]+tree[2*i+2];

    }
    //cout<<"k="<<k<<endl;
    return tree;
}

void UpdateSum (vector<int> &ST, vector<int> &A, int i, int X) {
    //cout<<"Hello"<<i<<endl;
  	A[i]+=X;

    int k=1;

    while (k<A.size()){
        k*=2;
    }
    
  	i=i+k-1;
    ST[i]+=X;
	int p = (i-1)/2;
  	while(true){
          //cout<<p<<endl;
        if(p!=0){  
            //cout<<"Befote:"<<ST[p]<<endl;
            ST[p]+=X;
            //cout<<"After:"<<ST[p]<<endl;
            p = (p-1) / 2;
        }else{
            //cout<<"Befote:"<<ST[p]<<endl;
            ST[p]+=X;
            //cout<<"After:"<<ST[p]<<endl;
            break;
        }
	}
    //cout<<"Meow"<<endl;
}

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}

vector<int> countSmaller(vector<int>& nums) {
    //numbers are from -10000 to 10000
    //mapping is from 0 to 20000
    // create frequency array
    vector<int> freq;
    for (int i=0; i<10001; i++){
        freq.push_back(0);
    }
    vector<int> freqTree = createSumTree(freq);
    //printVector(freqTree);

    vector<int> res(nums.size());

    for (int i=nums.size()-1; i>-1; i--){
        //cout<<nums[i]<<endl;
        UpdateSum(freqTree, freq, nums[i], 1);
        /*for (int i=16383; i<16393; i++){
            cout<<freqTree[i]<<endl;
        }
        cout<<"Meow"<<endl;
        int sum=0;
        for (int j=0; j<nums[i]; j++){
            sum+=freqTree[16383+j];
        }
        cout<<"Sum = "<<sum<<endl; */
        int res1=querySum(freqTree, freq, 0, nums[i]-1);
        //cout<<res1<<endl;
        res[i]=res1;
    }
    return res;
}

int main(){
    //vector<int> arr= {1,2,3,4,5};
    //vector<int> res= createSumTree(arr);
    //printVector(res);
    //cout<<querySum(res, arr, 2,4)<<endl;
    //UpdateSum(res, arr, 3, 1);
    //cout<<querySum(res, arr, 2, 4)<<endl;
    //UpdateSum(res, arr, 2, 2);
    //cout<<querySum(res, arr, 2, 4)<<endl;
    //printVector(res);
    /*printVector(arr);
    printVector(res);
    cout<<querySum(res, arr, 2, 4)<<endl; */

    vector<int> test = {5,2,6,1};
    vector<int> res = countSmaller(test);
    printVector(res); 
}