#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int n=s.size();
    unordered_map<char, int> lastIndex;

    int left=0, maxLen=0;

    for(int right=0; right<n; right++){
        if(lastIndex.find(s[right])!=lastIndex.end()){
            left=max(left, lastIndex[s[right]]+1);
        }
        lastIndex[s[right]]=right;
        maxLen=max(maxLen, right-left+1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;    // 1
}