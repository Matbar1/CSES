#include <iostream>
#include <unordered_map>
#include <vector>

long long countSubarraysWithSum(const std::vector<int>& arr, int targetSum) {
    int n = arr.size();
    std::unordered_map<long long, int> prefixSumCount;
    long long prefixSum = 0;
    long long count = 0;

    prefixSumCount[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        long long complement = prefixSum - targetSum;

        if (prefixSumCount.count(complement) > 0) {
            count += prefixSumCount[complement];
        }

        prefixSumCount[prefixSum]++;
    }

    return count;
}

int main() {
    int n, targetSum;
    std::cin >> n >> targetSum;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long result = countSubarraysWithSum(arr, targetSum);

    std::cout << result << std::endl;

    return 0;
}
