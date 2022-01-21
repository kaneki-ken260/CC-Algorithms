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
    int minsofar=a[0],maxprofit=0;
    for (int i = 0; i < n; i++)
    {
        minsofar = min(minsofar,a[i]);
        int profit = a[i]-minsofar;
        maxprofit = max(maxprofit,profit);
    }
    cout<<maxprofit;
    
    return 0;
}
