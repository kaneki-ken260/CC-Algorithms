/*
  sorting a k sorted array/ sorting a nearly sorted array

  basically, it means that an element that should have been at ith index in its sorted form will be in the range of [i-k,i+k]th index.
I/P: arr[] = 6 5 3 2 8 10 9
         k = 3
         that is an element that should have been at i will be in the range [i-3,i+3]

O/P: sorted array.

The reason we use min heap here is because in min heap the element at the top will be the minimum.

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

    priority_queue <int, vector<int>, greater<int>> mnh;  //syntax of min heap

    vector <int> v;  // to store the sorted array.

    for (int i = 0; i < n; i++)
    {
        mnh.push(a[i]);
        if(mnh.size()>k)
        {
            v.push_back(mnh.top());
            mnh.pop();
        }
    }
    while (mnh.size()>0)
    {
        v.push_back(mnh.top());
        mnh.pop();
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
