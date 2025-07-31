#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(const string &text, const string &pattern) {
    const int base = 256;      // base value for characters (ASCII)
    const int mod = 1e9 + 7;   // large prime number for modulus

    int n = text.size();
    int m = pattern.size();
    vector<int> result;

    if (m > n) return result; // pattern longer than text

    long long patternHash = 0, windowHash = 0, power = 1;

    // Precompute base^(m-1) % mod for rolling hash
    for (int i = 0; i < m - 1; i++)
        power = (power * base) % mod;

    // Initial hash values
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
    }

    // Slide the window
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            if (text.substr(i, m) == pattern) // check actual string
                result.push_back(i);
        }

        // Roll the hash: remove left char and add right char
        if (i < n - m) {
            windowHash = (windowHash - text[i] * power % mod + mod) % mod; // remove old char
            windowHash = (windowHash * base + text[i + m]) % mod;          // add new char
        }
    }

    return result;
}

int main() {
    string text = "ababcabcababc";
    string pattern = "abc";

    vector<int> indices = rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int i : indices) cout << i << " ";
    cout << endl;

    return 0;
}
