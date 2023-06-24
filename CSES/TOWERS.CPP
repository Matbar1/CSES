#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = upper_bound(towers.begin(), towers.end(), x);
        if (it == towers.end()) {
            towers.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << towers.size() << endl;

    return 0;
}
