#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    for (int i = 1; i < n; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    vector<int> lps = computeLPS(combined);
    int longestPalPrefix = lps.back();
    string suffix = s.substr(longestPalPrefix);
    reverse(suffix.begin(), suffix.end());
    return suffix + s;
}
