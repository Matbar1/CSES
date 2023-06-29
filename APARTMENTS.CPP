#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> desiredSizes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> desiredSizes[i];
    }

    std::vector<int> apartmentSizes(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> apartmentSizes[i];
    }

    std::sort(desiredSizes.begin(), desiredSizes.end());
    std::sort(apartmentSizes.begin(), apartmentSizes.end());

    int count = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (apartmentSizes[j] >= desiredSizes[i] - k && apartmentSizes[j] <= desiredSizes[i] + k) {
            ++count;
            ++i;
            ++j;
        } else if (apartmentSizes[j] < desiredSizes[i] - k) {
            ++j;
        } else { // apartmentSizes[j] > desiredSizes[i] + k
            ++i;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
