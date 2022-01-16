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
void insert(stack <int> &st, int temp)
{
   if(st.empty())
   {
       st.push(temp);
       return;
   }
   int val = st.top();
   st.pop();
   insert(st,temp);
   st.push(val);
}
void reverse(stack <int> &st)         // Function to reverse the stack.
{
  if(st.empty())
  return;

  int temp = st.top();
  st.pop();
  reverse(st);
  insert(st,temp);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    stack <int> st;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        st.push(x);
    }
    reverse(st);
    printstacks(st);
    return 0;
}
