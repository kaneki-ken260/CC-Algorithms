#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;
int t[102][1002] = {-1};

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    return 0;

    if(wt[n-1]<=w)
    {
        return t[n][w] = max((val[n-1] + knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));
    }

    else
    {
        return t[n][w] = knapsack(wt,val,w,n-1);
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,w;     // n is the number of items and w is the total capacity of the knapsack.
    cin>>n>>w;
    int val[n],wt[n];
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }
    cout<<knapsack(wt,val,w,n);
    return 0;
}
