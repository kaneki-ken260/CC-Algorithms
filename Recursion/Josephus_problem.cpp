#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(vector <int> &v, int k,int index, int &ans)
{
    if(v.size()==1)
    {
       ans = v[0];
       return;
    }

    index = (index+k)% v.size();  // The modulo is done as we have to move in a circle.
    v.erase(v.begin()+index);
    solve(v,k,index, ans);
    return;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,k;cin>>n>>k;
    vector <int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    k--;    // As we will be starting the count from the person itself.
    int index = 0;
    int ans = -1;
    solve(v,k,index,ans);
    cout<<ans;
    return 0;
}
