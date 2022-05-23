#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, pair<int, int>> ppi;
const int N = 1e5 + 10;

bool vis[N];
vector<int> graph[N];

vector <vector<int>> cc;
vector <int> current_cc;

void dfs(int vertex)
{
    // Code to take action on the vertex after entering the vertex

    // cout << vertex << endl;

    vis[vertex] = true;
    current_cc.push_back(vertex); // pushing the vertex in the current connected component
    for (int child : graph[vertex])
    {
        // code to take action on child before entering the child

    //    cout<< "par "<<vertex<<" child "<<child<<endl;

        if (vis[child])
            continue;
        dfs(child);

        // code to take action on the child after exiting the child
    }
    // code to take action on the vertex after exiting the vertex
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    // n is number of nodes and m is number of edges

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // since this is an undirected graph.
    }
    int ans=0;
   for (int i = 1; i <= n; i++)
   {
       if(!vis[i])
       {
           current_cc.clear();
           dfs(i);
           cc.push_back(current_cc);
           ans++;
       }
   }
   cout<<ans<<endl;
   for (int i = 0; i < cc.size(); i++)
   {
       for (int j = 0; j < cc[i].size(); j++)
       {
           cout<<cc[i][j]<<" ";
       }
       cout<<endl;
   }
   
    return 0;
}