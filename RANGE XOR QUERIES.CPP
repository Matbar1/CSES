#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Calculate prefix XOR sums
    vector<int> prefixXOR(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixXOR[i] = prefixXOR[i - 1] ^ numbers[i - 1];
    }

    // Process the queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int xorSum = prefixXOR[b] ^ prefixXOR[a - 1];
        cout << xorSum << endl;
    }

    return 0;
}
