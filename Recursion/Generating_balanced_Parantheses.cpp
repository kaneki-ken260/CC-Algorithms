#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector <string> &v, int open, int close,string op)
{
  if(close==0 && open==0)
  {
      v.push_back(op);
      return;
  }
  if(open!=0)
  {
      string op1=op;
      op1.push_back('(');
      solve(v,open-1,close,op1);
  }
  if(close>open)
  {
      string op2 = op;
      op2.push_back(')');
      solve(v,open,close-1,op2);  
  }
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;cin>>n;
    vector <string> v;
    int open = n, close = n;
    string op = "";
    solve(v,open,close,op);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }  
    return 0;
}
