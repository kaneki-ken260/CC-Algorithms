#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, pair<int, int>> ppi;
const int N = 1e5 + 10;

bool vis[N];
vector<int> graph[N];

void dfs(int vertex)
{
    // Code to take action on the vertex after entering the vertex

    cout << vertex << endl;

    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        // code to take action on child before entering the child

       cout<< "par "<<vertex<<" child "<<child<<endl;

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
   dfs(1);
    return 0;
}