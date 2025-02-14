/*Given two strings s and t of lengths m and n respectively, return the minimum window substring
 of s such that every character in t (including duplicates) is included in the window. 
 If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 */

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
    vector<int> tFreq(128, 0), windowFreq(128, 0);
    for(char c:t) tFreq[c]++;
    int left=0, right=0, required=t.size(), minLen=INT_MAX, starIdx=0;

    while(right<s.size()){
        if(tFreq[s[right]]>0){
            if(windowFreq[s[right]]<tFreq[s[right]]) required--;
            windowFreq[s[right]]++;
        }
        while(required==0){
            if(right-left+1<minLen){
                minLen=right-left+1;
                starIdx=left;
            }
            if(tFreq[s[left]]>0){
                windowFreq[s[left]]--;
                if(windowFreq[s[left]]<tFreq[s[left]]) required++;
            }
            left++;
        }
        right++;
    }
    return minLen==INT_MAX?"" : s.substr(starIdx, minLen);
}


int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl; 
    return 0;
}