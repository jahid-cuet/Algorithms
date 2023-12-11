#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> adj[N]; // Every index of the array will contain a vector
bool visited[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n; // Number of nodes (houses)
    int m; // Number of edges (roads)
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // This is for one-way roads only
    }

    int f; // Kamal's house number
    cin >> f;

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Perform a breadth-first search starting from Kamal's house
    bfs(f);

    int c = 0;

    // Count the houses that Kamal can reach (directly or indirectly)
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            c++;
        }
    }

    cout << c;

    return 0;
}





