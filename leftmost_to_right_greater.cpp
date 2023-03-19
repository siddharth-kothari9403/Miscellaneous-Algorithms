//this code is the binary search in segment tree code, very important
//O(log n) algorithm
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int RMQ(vector<int> maxTree, vector<int> arr, int ss, int se, int l, int r, int i){
    if (l<=ss && r>=se){
        return maxTree[i];
    }else if(se<l || ss> r){
        return -1;
    }

    int mid = (ss+ se)/2;
    int m1 = RMQ(maxTree,arr, ss, mid, l, r, 2*i+1);
    int m2 = RMQ(maxTree,arr,  mid+1, se, l, r, 2*i+2);

    if (m1==-1){
        return m2;
    }else if (m2 == -1){
        return m1;
    }

    if (arr[m1]<arr[m2]){
        return m2;
    }else{
        return m1;
    }
}

vector<int> build_max(vector<int> arr){
    int c = 1;
    while (c<arr.size()){
        c*=2;
    }
    vector<int>tree1(2*c-1,0);
    for (int i=0; i<arr.size(); i++)
    {  
        tree1[c-1+i] = i;
    }

    for(int i=arr.size();i<c;i++)
    {
        tree1[c+i-1] = i;
        arr.push_back(INT_MIN); // we are just creating imaginary indexes which are not present in the original array and for those imaginary indexes we are filling it with infinite value in the original array.
    }
    
    for (int i = c - 2; i > -1; --i)    
    {
        if (arr[tree1[2*i+1]] >= arr[tree1[2*i+2]]){
            tree1[i]=tree1[2*i+1];
        }
        else{
            tree1[i]=tree1[2*i+2];
        } 
    }
    return tree1;
}

vector<int> leftmost_to_right_greater(vector<int> arr){
    vector<int> tree= build_max(arr);
    vector<int> res(arr.size());

    int c = 1;
    while(c<arr.size()){
        c*=2;
    }
    for (int i=0; i<arr.size(); i++){
        if (arr[RMQ(tree, arr, 0, c-1, i+1, arr.size()-1, 0)]> arr[i]){
            int l=i+1, r=arr.size()-1;
            int mid;

            while (l<r){
                mid = (l+r)/2;
                int temp = RMQ(tree, arr, 0, c-1, i+1, mid, 0);
                if (arr[temp]> arr[i]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }

            res[i]=arr[l];
        }

        else{
            res[i]=-1;
        }
    }
    return res;

}

int main(){
    vector<int> test = {3,7,4,1,8,0,5};
    vector<int> res = leftmost_to_right_greater(test);
    printVector(res);
}