#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<bool> seen(n + 1, false);
    
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        seen[num] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}
