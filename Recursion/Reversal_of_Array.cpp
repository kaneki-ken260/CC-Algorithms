#include <bits/stdc++.h>
using namespace std;
#define ll long long
void reverse(vector <int> &v,int start, int end)
{
  if(start>=end)
  return;

  int temp = v[start];
  v[start]=v[end];
  v[end]=temp;
  reverse(v,start+1,end-1);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
   
    int n;cin>>n;
 vector <int> v;
 cout<<"Original Vector is: ";
 for (int i = 0; i < n; i++)
 {
     int x;cin>>x;
     v.push_back(x);
     cout<<x<<" ";
 }
 reverse(v,0,n-1);
 cout<<endl<<"Reversed Vector is: ";
 for (int i = 0; i < n; i++)
 {
     cout<<v[i]<<" ";
 }
    return 0;
}
