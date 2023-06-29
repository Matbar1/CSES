#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
vector<int> cycle;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) {
                return true;
            }
        } else if (neighbor != par) {
            // Cycle detected
            int current = node;
            cycle.push_back(current);

            while (current != neighbor) {
                current = parent[current];
                cycle.push_back(current);
            }

            cycle.push_back(node);

            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    parent.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                int cycleSize = cycle.size();
                cout << cycleSize << endl;
                for (int j = cycleSize - 1; j >= 0; j--) {
                    cout << cycle[j] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
