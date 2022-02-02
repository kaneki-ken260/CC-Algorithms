/*
  Top K frequent numbers

  Here we have to print Top k numbers having the greatest frequency in the given array
  
I/P: arr[] = 1 1 1 3 2 2 4
         k = 2

O/P: 1 2 or in any order.

 So we will be using a min heap as we want largest frequency elements.

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

    
    unordered_map <int,int> mp;  // To store the frequency of the elements.

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    
    priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> mnh;  // syntax for minimum heap with pair.

   
    for(auto i = mp.begin();i!=mp.end();i++)
    {
        mnh.push(make_pair(i->second, i->first));       // Pushing in the heap (frequency as the key and a[i] as the value)

        if(mnh.size()>k)
        mnh.pop();
    }

    while (mnh.size()>0)
    {
        cout<<mnh.top().second<<" ";
        mnh.pop();
    }

    return 0;
}
