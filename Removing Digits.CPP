#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSteps(int n) {
    // Create a vector to store the minimum steps required for each number
    vector<int> dp(n + 1, INT_MAX);
    // Base case: Minimum steps required to reach 0 is 0
    dp[0] = 0;

    // Iterate from 1 to n and calculate the minimum steps for each number
    for (int i = 1; i <= n; ++i) {
        int num = i;
        // For each digit in the number, calculate the minimum steps required
        while (num > 0) {
            int digit = num % 10;
            // Remove the digit and update the minimum steps if necessary
            if (digit != 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            num /= 10;
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int result = minSteps(n);
    cout << result << endl;

    return 0;
}
