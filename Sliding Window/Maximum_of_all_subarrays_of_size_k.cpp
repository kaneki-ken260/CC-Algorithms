#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
  vector <int> v;
  int i=0,j=0;
 list <int> l;
  while (j<n)
  {
    while (l.size()>0 && l.back()<a[j])    // As all the elements even if smaller than the current element can be useful for the upcoming window but the elements smaller than the current max an coming before are of no use so they must be popped out from the list.
    {
      l.pop_back();
    }
    l.push_back(a[j]);

    if(j-i+1<k)j++;

    else if(j-i+1==k)
    {
      v.push_back(l.front());
      if(l.front()==a[i])
      l.pop_front();
      i++;
      j++;
    }
  }
  for (int i = 0; i < v.size(); i++)
  {
    cout<<v[i]<<" ";
  }
  
  return 0;
}
