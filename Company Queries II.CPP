#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 200005;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][MAXLOG];

void dfs(int node, int par, int dep) {
    depth[node] = dep;
    parent[node][0] = par;

    for (int i = 1; i < MAXLOG; i++) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (int child : adj[node]) {
        if (child != par)
            dfs(child, node, dep + 1);
    }
}

int getKthParent(int node, int k) {
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (k >= (1 << i)) {
            node = parent[node][i];
            k -= (1 << i);
        }

        if (node == -1)
            break;
    }

    return node;
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    u = getKthParent(u, diff);

    if (u == v)
        return u;

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1, -1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = getLCA(u, v);
        cout << lca << endl;
    }

    return 0;
}
