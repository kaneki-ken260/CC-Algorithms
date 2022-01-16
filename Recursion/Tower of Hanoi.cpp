#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int n,char s, char h, char d)
{
   if(n==1)
   {
       cout<<"Moving disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;;
       return;
   }
   solve(n-1,s,d,h);       // Here the job remaining is to move n-1 disks from source to helper rod so the destination here is the helper rod i.e rod B.
   cout<<"Moving disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
   solve(n-1,h,s,d);       // Here the job remaining is to move n-1 disks from helper to destination rod so the destination here is the rod C.
   return;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;cin>>n;
    char a='A';
    char b='B';
    char c='C';
    solve(n,a,b,c);
    return 0;
}
