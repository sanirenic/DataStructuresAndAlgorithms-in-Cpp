#include <bits/stdc++.h>
using namespace std;

int longestSubstringSlidingWindow(string s, int k) {
    int n = s.size();
    if (n == 0 || k == 0) return 0;

    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s = "aababbcaacc";
    int k = 2;
    cout << longestSubstringSlidingWindow(s, k) << endl;
}
