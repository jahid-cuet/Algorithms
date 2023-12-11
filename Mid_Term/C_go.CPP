#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>> adj[N];
long long d[N];
bool visited[N];
int n,m;

void dijkstra(int src, int des, int dw) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        visited[i] = false;
    }

    d[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long, int> f = pq.top();
        pq.pop();
    
        int selectNode = f.second;
        if (visited[selectNode]) continue;
        visited[selectNode] = true;

        for (auto child : adj[selectNode]) {
            long long edgeCost = child.first;
            int v = child.second;
            if (d[selectNode] + edgeCost < d[v]) {
                d[v] = d[selectNode] + edgeCost;
                pq.push({d[v], v});
            }
        }
    }

    if (d[des] <= dw) {
        cout << "yes" << endl;
    } else {
        cout << "not" << endl;
    }
}

int main() {
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int src;
    cin >> src; 

    int t;
    cin >> t;

    while (t--) {
        int des, dw;
        cin >> des >> dw;
        dijkstra(src, des, dw);
    }

    return 0;
}
