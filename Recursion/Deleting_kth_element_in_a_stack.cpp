#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printstacks(stack <int> &st)       // Function to print the stack as entered by us.
{
  if(st.empty())
  return;

  int x = st.top();
  st.pop();

  printstacks(st);

  cout<<x<<" ";

  st.push(x);
}
void solve(stack <int> &st,int k)
{
  if(k==1)        // smallest valid Input as the last element can be popped easily.
  {
      st.pop();return;
  }
  int val = st.top();
  st.pop();
  solve(st,k-1);
  st.push(val);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    stack <int> st;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        st.push(x);
    }
    solve(st,k);
    printstacks(st);
    return 0;
}
