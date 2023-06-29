#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

vector<vector<pair<int, ll>>> adj;
vector<ll> dist;

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        ll distance = pq.top().first;
        pq.pop();

        if (distance > dist[node])
            continue;

        for (auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            ll weight = neighbor.second;

            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
