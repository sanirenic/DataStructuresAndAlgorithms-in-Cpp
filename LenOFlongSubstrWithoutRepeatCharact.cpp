#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < n; right++) {
        while (window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // 1
}
