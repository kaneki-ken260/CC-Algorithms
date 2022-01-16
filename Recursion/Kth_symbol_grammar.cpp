
//Question is kth symbol grammar.
/*
     k 1 2 3 4 5 6 7 8 
   n
   1   0
   2   0 1
   3   0 1 1 0
   4   0 1 1 0 1 0 0 1

   Here the 0 in n-1th row splits into 0 1 in nth row and 1 splits up in 1 0
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n, int k)
{
   if(n==1 && k==1)
   return 0;

   else
   {
       int mid = (1<<(n-2));
       if(k<=mid)
       return solve(n-1,k);   // since 1st half is same as n-1;
       else
       return !solve(n-1,k-mid);  // since 2nd half is complement of the first half.
   }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,k;cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}
