#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long n = max(y, x);  // Find the maximum of y and x
        long long diag = (n - 1) * (n - 1);  // Calculate the diagonal number

        if (n % 2 == 0) {
            if (y <= x) {
                cout << diag + y << endl;
            } else {
                cout << diag + 2 * n - x << endl;
            }
        } else {
            if (x <= y) {
                cout << diag + x << endl;
            } else {
                cout << diag + 2 * n - y << endl;
            }
        }
    }

    return 0;
}
