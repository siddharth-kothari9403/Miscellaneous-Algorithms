# include <bits/stdc++.h>
using namespace std;
int prefixSum(int BIT[],int i) // this is used for finding the prefix sum till i element.
{
    int ans = 0;
    while(i>0)
    {
        ans +=BIT[i];// this will add the BIT element
        i-= i&(-i); // this will make sure that we can add the element at appropriate intervals(7 -add till element4,add till element 6,add the seventh element])
        //cout<<i<<endl;
    }
    //cout<<"Hello";
    return ans;
}


void update(int BIT[],int index,int val,int n)
{
    //BIT[index]+=val;
    while(index<=n)
    {
        //cout<<index<<endl;
        //cout<<index<< " "<<BIT[index]<<endl;
        BIT[index]+=val; // it will do the corresponding changes for the concerned elements.
        //int i=index;
        index += index &(-index);
        //cout<<i<<" "<<BIT[i]<<endl;
    }
}

int main()
{
    int a[12];
    for(int i=1;i<12;i++)
    {
        cin>>a[i];
    }
    int BIT[12];
    //cout<<"Heel";
    for(int i=1;i<=11;i++)
    {
        BIT[i]= 0;
    }
    for(int i=1;i<=11;i++)
    {
        //cout<<"H";
        update(BIT,i,a[i],11);
    }
    /*for (int i=1;i<=11;i++){
        cout<<BIT[i]<<endl;
    }*/
    int c = prefixSum(BIT,8) - prefixSum(BIT,3);
    cout<<c;
    int d = prefixSum(BIT,6);
    cout<<d;
    return 0;
}
