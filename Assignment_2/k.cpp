#include<bits/stdc++.h>
using namespace std;

const int N=1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &size)
{
    visited[u] = true;
    size++;

    for(int v : adj[u])
    {
        if(!visited[v])
            dfs(v, size);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> component_sizes;

    for(int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            int size = 0;
            dfs(i, size);
            if (size > 1) {
                component_sizes.push_back(size);
            }
        }
    }

    sort(component_sizes.begin(), component_sizes.end());

    for (int i = 0; i < component_sizes.size(); i++) {
        cout << component_sizes[i];
        if (i < component_sizes.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}