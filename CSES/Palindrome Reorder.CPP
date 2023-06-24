#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string palindromeReorder(string s) {
    int n = s.length();
    vector<int> freq(26, 0);

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    // Find the character with an odd frequency (if exists)
    char oddChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            if (oddChar != '\0') {
                // If there is already an odd frequency character, palindrome is not possible
                return "NO SOLUTION";
            }
            oddChar = 'A' + i;
        }
    }

    // Construct the palindrome string
    string palindrome = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && 'A' + i != oddChar) {
            string part(freq[i] / 2, 'A' + i);
            palindrome = part + palindrome + part;
        }
    }

    // If there was a character with an odd frequency, add it to the middle
    if (oddChar != '\0') {
        string part(freq[oddChar - 'A'], oddChar);
        palindrome = palindrome.substr(0, palindrome.length() / 2) + part +
                     palindrome.substr(palindrome.length() / 2);
    }

    return palindrome;
}

int main() {
    string s;
    cin >> s;

    string result = palindromeReorder(s);
    cout << result << endl;

    return 0;
}
