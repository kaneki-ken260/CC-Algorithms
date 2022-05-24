#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;

const int N = 1e5+10;
vector <int> graph[N];
int depth[N];

void dfs(int v,int par=-1)
{
   for(int child:graph[v])
   {
       if(child==par) continue;
       depth[child] = depth[v] + 1; // Depth is calculated while going down the tree so we take action on the child just after entering the child node.
       dfs(child,v);
   }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    
    int n;cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1); // Calculating the node with max depth

    int mx_depth=-1;int mx_node;

    for(int i=1;i<=n;i++)
    {
        if(mx_depth<depth[i])
        {
            mx_depth=depth[i];
            mx_node=i;
        }
        depth[i]=0; // Resetting the value of depth array
    }
  dfs(mx_node); // Calling the function to calculate the node with max depth again but from a different node
  for (int i = 1; i <= n; i++)
  {
      if(mx_depth<depth[i])
      mx_depth=depth[i];
  }
  
  cout<<mx_depth<<endl;
    return 0;
}