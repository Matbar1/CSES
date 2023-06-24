#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
    } else if (n < 4) {
        cout << "NO SOLUTION" << endl;
    } else {
        vector<int> permutation;
        
        for (int i = 2; i <= n; i += 2) {
            permutation.push_back(i);
        }
        
        for (int i = 1; i <= n; i += 2) {
            permutation.push_back(i);
        }
        
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
