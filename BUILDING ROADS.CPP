#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    if (parentX != parentY)
        parent[parentY] = parentX;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize parent array
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Process the roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    // Find representatives of each set
    vector<int> representatives;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i)
            representatives.push_back(i);
    }

    // Print the number of representatives and the road connections
    cout << representatives.size() - 1 << endl;
    for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
    }

    return 0;
}
