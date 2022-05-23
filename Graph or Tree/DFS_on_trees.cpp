#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;

const int N = 1e5+10;

vector <int> graph[N];

int depth[N],height[N];

void dfs(int vertex,int par=0) // default value of par=0 if no value is passed

// The need of the parent variable is to ensure that we don't go back to the parent node while apllying dfs on child node 

{
  for(int child:graph[vertex])
  {
    if(child==par) continue;
    depth[child] = depth[vertex] + 1;
    dfs(child,vertex);

    height[vertex] = max(height[vertex] , height[child] + 1);
  }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n;
cin>>n;

for (int i = 0; i < n-1; i++) //since in a tree we have n-1 edges for n nodes
{
    int v1,v2;
    cin>>v1>>v2;

    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

dfs(1);

for (int i = 1; i <= n; i++)
{
    cout<<depth[i]<<" "<<height[i]<<endl;
}

    
    return 0;
}