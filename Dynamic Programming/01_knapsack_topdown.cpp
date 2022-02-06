/*
In order to write the topdown code we just have to replace the n with i and w with j in the recursive solution of knapsack.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;
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
    
    int t[n+1][w+1];
    for (int i = 0; i < n+1; i++)         // Initialising the first row and column of the matrix with zero.
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i==0 || j==0)
            t[i][j]=0; 
        }
        
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(wt[i-1]<=j)                                             // If the weight of the current item is less than or equal to the capacity of knapsack.
            t[i][j] = max((val[i-1] + t[i-1][j-wt[i-1]]),t[i-1][j]);   // Here we try to store the max profit from either taking the the item or leaving it.

            else
            t[i][j] = t[i-1][j];     // Here the weight od item is greater than the capacity of the knapsack so we skip this item.
        }
        
    }
    
    cout<<t[n][w];     // This will store the answer for the problem.

    return 0;
}