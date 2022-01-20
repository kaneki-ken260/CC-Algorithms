/*
Here the input is an alphanumeric string.
Example:
I/P: a1b2
O/P: A1b2, A1B2, a1b2, a1B2
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(string ip,string op,vector <string> &v)
{
   if(ip.length()==0)
   {
       v.push_back(op);
       return;
   }
    if(ip[0]>=48 && ip[0]<=57)  // If it is a digit then we only have one choice that is to include this in the output.
   {   string op1=op;
       op1.push_back(ip[0]);
       ip.erase(ip.begin()+0);  // ab gets converted to b
       solve(ip,op1,v);
   }
    else                      // If it is an alphabet then we have two choices that is to include this either in uppercase or lowercase.
    {
        string op1=op;
        string op2=op;
        op1.push_back(ip[0]-32);
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);  // ab gets converted to b
        solve(ip,op1,v);
        solve(ip,op2,v);
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    string ip;cin>>ip;
    string op = "";
    vector <string> v;
    solve(ip,op,v);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}
