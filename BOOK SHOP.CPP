#include <iostream>
#include <vector>

using namespace std;

int maxPages(int n, int x, vector<int>& prices, vector<int>& pages) {
    // Create a 2D vector to store the maximum number of pages for each price limit and book
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // Iterate through each book
    for (int i = 1; i <= n; ++i) {
        int price = prices[i - 1];
        int page = pages[i - 1];
        // Iterate through each possible price limit
        for (int j = 1; j <= x; ++j) {
            // If the current book price is less than or equal to the price limit,
            // we consider two options: including the current book or excluding it
            if (price <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + page);
            }
            // If the current book price is greater than the price limit, we can only exclude it
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    int result = maxPages(n, x, prices, pages);
    cout << result << endl;

    return 0;
}
