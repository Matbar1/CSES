#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the prefix sum
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        // Calculate the sum of values in the range [a, b]
        long long sum = prefixSum[b] - prefixSum[a - 1];
        cout << sum << endl;
    }

    return 0;
}
