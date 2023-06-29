#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    std::sort(weights.begin(), weights.end());

    int left = 0, right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            // If the sum of weights at left and right pointers is less than or equal to x
            // Both children can ride together in a gondola
            left++;
            right--;
        } else {
            // If the sum exceeds x
            // The child with higher weight can ride alone in a gondola
            right--;
        }

        // Increment the gondola count
        gondolas++;
    }

    std::cout << gondolas << "\n";

    return 0;
}
