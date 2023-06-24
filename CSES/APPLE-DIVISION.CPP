#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> apples;
long long minDifference = INT64_MAX;

void divideApples(int index, long long sum1, long long sum2) {
    if (index == apples.size()) {
        // Calculate the difference between the two sums
        long long difference = abs(sum1 - sum2);
        minDifference = min(minDifference, difference);
        return;
    }

    // Add the current apple to sum1 and recurse
    divideApples(index + 1, sum1 + apples[index], sum2);

    // Add the current apple to sum2 and recurse
    divideApples(index + 1, sum1, sum2 + apples[index]);
}

int main() {
    int n;
    cin >> n;

    apples.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    divideApples(0, 0, 0);

    cout << minDifference << endl;

    return 0;
}
