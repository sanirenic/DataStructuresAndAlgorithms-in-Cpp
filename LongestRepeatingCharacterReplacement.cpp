/*424. Longest Repeating Character Replacement

You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter
 you can get after performing the above operations.*/

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k){
    vector<int> count(26, 0);
    int maxFreq=0;
    int left=0, maxLen=0;

    for(int right=0; right<s.length(); right++){
        count[s[right]-'A']++;
        maxFreq=max(maxFreq, count[s[right]-'A']);

        while((right-left+1)-maxFreq>k){
            count[s[left]-'A']--;
            left++;
        }
        maxLen=max(maxLen, right-left+1);
    }
    return maxLen;
}


int main() {
    string s = "AABABBA";
    int k = 1;
    cout << "Longest repeating substring length: " << characterReplacement(s, k) << endl;
    return 0;
}