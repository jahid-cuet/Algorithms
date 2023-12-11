#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // Every index of array will contain Vector
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
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main() {
    int n; // Number of nodes (houses)
    int m; // Number of edges (roads)
    cin >> n >> m;
    for (int i = 0; i < m; i++) { // take the number of edges as input
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // This is for the undirected list
    }

    int f;
    cin >> f;
    int c = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        level[i] = 0;
    }
    bfs(f);

    // If level is 1, then the house is directly connected to Kamal's house
    for (int i = 0; i < n; i++) {
        if (visited[i] && level[i] == 1) {
            c++;
        }
    }
    cout << c;

    return 0;
}