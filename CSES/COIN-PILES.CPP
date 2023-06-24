#include <iostream>

using namespace std;

string canEmptyPiles(int a, int b) {
    // Check if the difference between a and b is divisible by 3
    // If it is, it means that both piles can be emptied
    if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        string result = canEmptyPiles(a, b);
        cout << result << endl;
    }

    return 0;
}
