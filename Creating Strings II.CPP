#include <bits/stdc++.h>
using namespace std;
#define int long long
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N]; // fact[i] = i!
signed main () {
    string s; cin >> s;
    sort(s.begin(), s.end());
    fact[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        fact[i] = i * fact[i - 1] % M;
    }
    int ans = fact[s.length()];
    int len = 1; // number of consecutive letters
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) len++;
        else {
            ans = ans * inv(fact[len], M) % M;
            len = 1;
        }
    }
    ans = ans * inv(fact[len], M) % M;
    cout << ans << endl;
}