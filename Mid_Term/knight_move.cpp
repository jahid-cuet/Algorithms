#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
int ki, kj;
int qi, qj;
int dist[N][N];  // To store the minimum distance from knight to each cell
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({ki, kj});
    dist[ki][kj] = 0;  // Starting position of knight

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == qi && y == qj) {
            return dist[x][y];  // Found the queen
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;  // Queen cannot be reached
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        cin >> ki >> kj;
        cin >> qi >> qj;

        // Initialize the distance array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = -1;
            }
        }

        int minSteps = bfs();

        cout << minSteps << endl;
    }

    return 0;
}
