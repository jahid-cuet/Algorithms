#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &c)
{
    visited[u] = true;
    c++;
    for(int v : adj[u])
    {
        if(!visited[v])
            dfs(v, c);
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

    vector<int> elements;

    for(int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            int c = 0;
            dfs(i, c);
            if (c > 1) {
                elements.push_back(c);
            }
        }
    }

    sort(elements.begin(), elements.end());

    for (int c :elements) {
        cout << c<< " ";
    }

    return 0;
}