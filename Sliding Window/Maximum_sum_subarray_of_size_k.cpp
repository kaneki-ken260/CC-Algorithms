/*

Problem: Maximum subarray sum of size k.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int p=0,j=0;
    int n;cin>>n;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;v.push_back(x);
    }
    int k;cin>>k;
    int sum=0,mx=INT_MIN;
    while (j<v.size())
    {
        sum+=v[j];
        if(j-p+1<k)        // If the current window size is less than the required window size.
        j++;

        else if(j-p+1==k)
        {
            mx=max(mx,sum);
            sum=sum-v[p];
            p++;
            j++;
        }
    }
    cout<<mx;
    return 0;
}
