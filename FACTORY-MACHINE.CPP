#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& machines, int products, long long time) {
    long long totalProducts = 0;
    for (const auto& machine : machines) {
        totalProducts += time / machine;
        if (totalProducts >= products)
            return true;
    }
    return false;
}

long long minTimeToProduce(const vector<int>& machines, int products) {
    long long low = 0;
    long long high = 1e18; // Set a high upper bound for binary search

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(machines, products, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, products;
    cin >> n >> products;

    vector<int> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    long long minTime = minTimeToProduce(machines, products);
    cout << minTime << endl;

    return 0;
}
