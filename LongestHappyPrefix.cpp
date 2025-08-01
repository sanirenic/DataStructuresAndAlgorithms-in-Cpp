#include <iostream>
#include <vector>
using namespace std;

string longestPrefix(string s) {
    int n = s.size();
    vector<int> lps(n, 0); // lps[i] = length of longest prefix-suffix for s[0..i]

    for (int i = 1; i < n; ++i) {
        int len = lps[i - 1];

        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];

        if (s[i] == s[len])
            len++;

        lps[i] = len;
    }

    return s.substr(0, lps[n - 1]);
}

int main() {
    string s = "ababab";
    cout << longestPrefix(s) << endl; // Output: "abab"
}
