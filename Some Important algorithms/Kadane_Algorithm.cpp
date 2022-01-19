//Kadane's Algorithm

/*
Finding the maximum sum subarray of a given array.

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1 
of element (-1)


*/
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
    int sum=0,ans=0,neg=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0)
        neg++;
    }
    if(neg==n)                        // If all the elements are negative then answer will be the maximum of them.
    {
        int k = *max_element(a,a+n);
        cout<<k;
    }
    else
    {
        for (int i = 0; i < n; i++)
    {
        sum+=a[i];
        if(sum<0)                    // The moment the surrent sum <0 we make it 0 and discard the subaaray yielding negative sum.
        {
            sum=0;
        }
        ans = max(ans,sum);
    }
        cout<<ans;
    }
    return 0;
}