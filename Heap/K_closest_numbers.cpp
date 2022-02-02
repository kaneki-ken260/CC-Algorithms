/*
  K closest numbers

  So here we would be given a number x and we have to return K numbers that are closest to x in the array.
  Note that x need not be present in the array.
I/P: arr[] = 5 6 7 8 9
         k = 3
         x = 7
         
         So if we calculate the abs diff with each element.

O/P: 6 7 8 or in any order.

The reason we use max heap here is because in max heap the element at the top will be the maximum.
And in this we will be sorting the abs diff of every element.

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
    int k,x;cin>>k>>x;

    priority_queue <pair <int,int>> mxh;  //syntax of max heap with pair

    for (int i = 0; i < n; i++)
    {
        int p = abs(x-a[i]);
        mxh.push(make_pair(p,a[i]));   //first one is the abs diff and the second one is the element that has that particular abs diff.

        if(mxh.size()>k)
        mxh.pop();
    }
    while (mxh.size()>0)
    {
        cout<<mxh.top().second<<" ";
        mxh.pop();
    }

    return 0;
}
