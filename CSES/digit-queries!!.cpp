#include <iostream>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        long long k;
        std::cin >> k;

        long long len = 1, cnt = 9, start = 1;
        while (k > len * cnt) {
            k -= len * cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }

        start += (k - 1) / len;
        std::string num = std::to_string(start);
        std::cout << num[(k - 1) % len] << "\n";
    }

    return 0;
}
