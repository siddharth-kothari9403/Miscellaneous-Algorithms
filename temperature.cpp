//print first occurence of temperature to the right which is greater for each element
//extremely similar to leftmost to right greater

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

vector<int> dailyTemperatures(vector<int>& temperatures){
    vector<int> tree = build_max(temperatures);
    //printVector(tree);
    //cout<<temperatures.size()<<endl;
    int c=1;
    while (c<temperatures.size()){
        c*=2;
    }

    vector<int> res(temperatures.size());
    for (int i=0; i<temperatures.size()-1; i++){
        if (temperatures[RMQ(tree, temperatures, 0, c-1, i+1, temperatures.size()-1, 0)] > temperatures[i]){
            int l= i+1;
            int r= temperatures.size()-1;

            int mid;
            while (l<r){
                mid = (l+r)/2;
                if (temperatures[RMQ(tree, temperatures, 0, c-1, l, mid, 0)] > temperatures[i]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }

            res[i]=l-i;
        }else{
            res[i]=0;
        }
    }
    return res;
}

int main(){
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};
    printVector(dailyTemperatures(temperatures));
}
