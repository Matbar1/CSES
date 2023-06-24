#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> generateGrayCode(int n) {
    // Base case
    if (n == 1) {
        return {"0", "1"};
    }

    // Recursive case
    vector<string> prevGrayCode = generateGrayCode(n - 1);
    vector<string> grayCode;

    // Append 0 to the front of the previous Gray code sequence
    for (int i = 0; i < prevGrayCode.size(); i++) {
        grayCode.push_back("0" + prevGrayCode[i]);
    }

    // Append 1 to the front of the previous Gray code sequence in reverse order
    for (int i = prevGrayCode.size() - 1; i >= 0; i--) {
        grayCode.push_back("1" + prevGrayCode[i]);
    }

    return grayCode;
}

int main() {
    int n;
    cin >> n;

    vector<string> grayCode = generateGrayCode(n);

    for (string code : grayCode) {
        cout << code << endl;
    }

    return 0;
}
