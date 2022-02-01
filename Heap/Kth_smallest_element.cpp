/*

I/P: arr[] = 7 10 4 3 20 15
         k = 3
         that is 3rd smallest element needs to be returned.
O/P: 7

The solution below is using heap. This can be solved using sorting technique.

Complexity via heap = O(n*logk)
Complexity via sorting = O(n*logn)

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
    int n;cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int k;cin>>k;

    priority_queue <int> mxh;

    for (int i = 0; i < n; i++)
    {
        mxh.push(a[i]);
        if(mxh.size()>k)
        mxh.pop();
    }
    cout<<mxh.top();
    return 0;
}