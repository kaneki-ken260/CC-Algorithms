#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  string s1;cin>>s1;
  string s2;cin>>s2;
  map <char,int> mp;
  for (int i = 0; i < s2.length(); i++)
  {
    mp[s2[i]]++;
  }
  int count = mp.size();       // stores the distinct letters in the given pattern.
  int i=0,j=0,k=s2.length();
  int ans=0;
  while (j<s1.length())
  {
    mp[s1[j]]--;
    if(mp[s1[j]]==0)          // It means that one distinct letter is exhausted in the current window 
    count--;

    if(j-i+1<k)
    j++;
    else if(j-i+1==k)
    {
       if(count==0)
       ans++;

       if(mp.find(s1[i])!=mp.end())  // Now since we have to slide the window so we have to free the calculations of the previous element. So if it was present previously then now it will be incremented.
       mp[s1[i]]++;

       if(mp[s1[i]]>0)count++;      // Now if a certain letter has its count greater than 0 then we will increment the count variable storing the count of distinct letters.

       i++;j++;
    }
  }
  cout<<ans;
  return 0;
}
