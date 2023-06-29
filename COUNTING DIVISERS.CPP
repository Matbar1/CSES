#include <iostream>
#include <vector>

using namespace std;

vector<int> countDivisors(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        int count = 0;
        
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                // If the divisors are distinct, count them twice
                if (i * i != num)
                    count += 2;
                else
                    count++;
            }
        }
        
        result.push_back(count);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> divisors = countDivisors(nums);

    for (int count : divisors) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
