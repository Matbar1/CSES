#include <iostream>
#include <vector>

using namespace std;

long long maxSubarraySum(const vector<int>& arr) {
    int n = arr.size();
    long long maxSum = arr[0];
    long long currentSum = arr[0];

    for (int i = 1; i < n; ++i) {
        currentSum = max(static_cast<long long>(arr[i]), currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long maxSum = maxSubarraySum(arr);
    cout << maxSum << endl;

    return 0;
}
