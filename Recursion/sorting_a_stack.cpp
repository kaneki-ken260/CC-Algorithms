#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printstacks(stack <int> &st)
{
  if(st.empty())
  return;

  int x = st.top();
  st.pop();

  printstacks(st);

  cout<<x<<" ";

  st.push(x);
}
void insert(stack <int> &st , int temp)
{
  if(st.size()==1 || st.top()<=temp)
  {
      st.push(temp);
      return;
  }
  int val = st.top();
  st.pop();
  insert(st,temp);
  st.push(val);
}
void sort(stack <int> &st)
{
  if(st.size()==1)
  return;
  int temp = st.top();
  st.pop();
  sort(st);
  insert(st,temp);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    stack<int> st;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        st.push(x);
    }
    sort(st);
    printstacks(st);
    return 0;
}