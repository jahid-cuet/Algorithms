#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // Every index of the array will contain a vector
int visited[N];
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

    int Q;
    cin >> Q;

    while (Q--) {
        int f, d;
        cin >> f >> d;
        for (int i = 0; i < n; i++) {
            visited[i] = false; // Reset visited array for each query
        }
        bfs(f);

        if (visited[d]) {
            cout << level[d] << endl; // If destination is reachable, print the distance
        } else {
            cout << -1 << endl; // No path found
        }
    }

    return 0;
}