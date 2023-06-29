#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;

bool isBipartite(int start) {
    queue<int> q;
    q.push(start);
    colors[start] = 1; // Assign the first color

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (colors[neighbor] == 0) {
                colors[neighbor] = 3 - colors[node]; // Assign the opposite color
                q.push(neighbor);
            } else if (colors[neighbor] == colors[node]) {
                return false; // Not bipartite
            }
        }
    }

    return true; // Bipartite
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    colors.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            if (!isBipartite(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}
