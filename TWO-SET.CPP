#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int totalSum = (n * (n + 1)) / 2;

    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    int targetSum = totalSum / 2;

    vector<int> set1, set2;

    if (n % 4 == 0) {
        int k = n / 4;

        for (int i = 1; i <= n; i++) {
            if (i <= k || i > 3 * k) {
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        }
    } else if (n % 4 == 3) {
        int k = n / 4;

        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);

        for (int i = 4; i <= n; i++) {
            if (i <= k + 3 || i > 3 * k + 3) {
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        }
    } else {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << set1.size() << endl;
    for (int num : set1)
        cout << num << " ";
    cout << endl;

    cout << set2.size() << endl;
    for (int num : set2)
        cout << num << " ";
    cout << endl;

    return 0;
}
