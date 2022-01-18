#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(string ip,string op)
{
   if(ip.length()==0)
   {
       cout<<op<<" ";
       return;
   }
   string op1 = op;
   string op2 = op;

   op2.push_back(ip[0]);
   ip.erase(ip.begin()+0);  // ab gets converted to b
   solve(ip,op1);
   solve(ip,op2);
   return;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    string ip;cin>>ip;
    string op = "";
    solve(ip,op);
    return 0;
}
