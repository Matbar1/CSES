#include <iostream>

using namespace std;

const int MOD = 1000000007;

// Function to calculate the modular exponentiation of a^b modulo MOD
long long powerMod(long long a, long long b) {
    if (b == 0)
        return 1;

    long long res = powerMod(a, b / 2) % MOD;
    res = (res * res) % MOD;

    if (b % 2 == 1)
        res = (res * a) % MOD;

    return res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        long long result = powerMod(a, b);
        cout << result << endl;
    }

    return 0;
}
