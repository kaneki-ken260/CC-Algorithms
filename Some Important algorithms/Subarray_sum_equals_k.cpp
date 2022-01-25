#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;cin>>n;
    map <ll,int> mp;
    ll currsum=0;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    int k;cin>>k;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        currsum+=v[i];
        if(currsum == k)
        {
          count++;
        }
        else if(mp.find(currsum-k)!=mp.end())
        {
            count++;
        }
        mp[currsum]=i;
    }
    cout<<count;
    return 0;
}
