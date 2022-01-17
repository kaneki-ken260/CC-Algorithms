/*
Approach:  First we find the xor of two numbers to find which all bits are different.
           Then we count the number of set bits in the resultant xor.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int countbits(int a,int b)
{
    int n = a^b;
    int cnt=0;
    while (n>0)
    {
        if(n&1)
            cnt++;
            n=n>>1;
    }
    return cnt;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int a,b;cin>>a>>b;
    cout<<countbits(a,b);
    return 0;
}
