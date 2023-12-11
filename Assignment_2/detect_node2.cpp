#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // Every index of the array will contain a vector
bool visited[N];
int level[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
        }
    }
}

int main() {
    int n; // Number of nodes
    int m; // Number of edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) { // Take the number of edges as input
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For the undirected graph
    }

    int L;
    cin >> L;

    // Reset visited array for each query
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    bfs(0);

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (visited[i] && level[i] == L) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << -1;
    }

    return 0;
}