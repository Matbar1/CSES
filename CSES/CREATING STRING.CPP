#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void generatePermutations(string& str, int index, set<string>& permutations) {
    if (index == str.length() - 1) {
        permutations.insert(str);
        return;
    }

    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        generatePermutations(str, index + 1, permutations);
        swap(str[index], str[i]); // backtrack
    }
}

int main() {
    string input;
    cin >> input;

    set<string> permutations;
    generatePermutations(input, 0, permutations);

    cout << permutations.size() << endl;
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
