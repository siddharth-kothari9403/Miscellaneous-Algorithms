#include<bits/stdc++.h>
using namespace std;

int minCostHelper(vector<vector<int>> costs, int i, int bitmask){
    int n = costs.size();
    //break condition is when i=n, here we return 0 as we want it to not affect the sum
    if (i<n){
        int ans = INT_MAX;
        for (int k=0; k<n; k++){
            //if the job has been taken, bit =1 else bit = 0
            //this statement checks that condition
            if ((bitmask & (1<<k))==0){
                //update ans
                // we take costs[k][i] and pass i+1 and updated bitmask for recursive call
                //i represents the ith job
                ans = min(ans, costs[k][i]+ minCostHelper(costs, i+1, bitmask | (1<<k)));
            }
        }
        return ans;
    }else{
        return 0;
    }
}

int minCost(vector<vector<int>> costs){
    return minCostHelper(costs, 0, 0);
}

int main(){
    vector<vector<int>> costMatrix =
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
    cout<<minCost(costMatrix);
    return 0;
}