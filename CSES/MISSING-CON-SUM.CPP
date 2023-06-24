#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Sort the coins in ascending order
    sort(coins.begin(), coins.end());

    long long int currentSum = 0;
    for (int i = 0; i < n; i++) {
        // If the next coin value is greater than the current sum + 1, it means we've found the smallest missing coin sum
        if (coins[i] > currentSum + 1) {
            break;
        }

        currentSum += coins[i];
    }

    // The smallest missing coin sum is the current sum + 1
    cout << currentSum + 1 << endl;

    return 0;
}
