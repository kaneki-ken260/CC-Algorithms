/*
  Frequency Sort

  We have to sort the given array according to the decreasing frequency of the elements.
  
I/P: arr[] = 1 1 1 3 2 2 4

O/P: 1 1 1 2 2 3 4 or 1 1 1 2 2 4 3 

since 3 and 4 are having same frequency so their order may vary.

 So we will be using a max heap as we want element with greater frequency at the top.

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
    unordered_map <int,int> mp;  // To store the frequency of the elements.

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    
    priority_queue <pair<int,int>> mxh;  // syntax of max heap.


    for(auto i = mp.begin();i!=mp.end();i++)
    {
        mxh.push(make_pair(i->second, i->first));
    }

    while (mxh.size()>0)
    {
        int p = mxh.top().first;
        while (p--)
        {
            cout<<mxh.top().second<<" ";
        }
        mxh.pop();
    }

    return 0;
}
