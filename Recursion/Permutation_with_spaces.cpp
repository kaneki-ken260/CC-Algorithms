/*
Problem Statement:
We are given a string and we need to print all the possible permutations of spaces between them.

Example:
I/P:  ABC
O/P:  ABC
      A BC
      AB C
      A B C
      
I/P:  ABCD
O/P:  A B C D
      A B CD
      A BC D
      A BCD
      AB C D
      AB CD
      ABC D
      ABCD
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(string ip,string op)
{
   if(ip.length()==0)
   {
       cout<<op<<endl;
       return;
   }
   string op1 = op;
   string op2 = op;

   op1.push_back(' ');
   op1. push_back(ip[0]);

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
    op.push_back(ip[0]);      // This is done as we don't have choice for the first element we have to take it without spaces only.
    ip.erase(ip.begin()+0);
    solve(ip,op);
    return 0;
}
