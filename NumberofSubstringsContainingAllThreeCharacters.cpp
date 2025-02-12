/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 */

#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s){
    unordered_map<char, int> freq;
    int left=0, count=0, n=s.size();

    for(int right=0; right<n; right++){
        freq[s[right]]++;

        while(freq['a']>0 && freq['b']>0 && freq['c']>0){
            count+=(n-right);
            freq[s[left]]--;
            left++;
        }
    }
    return count;
}


int main() {
    string s = "abcabc";
    cout << countSubstrings(s) << endl;
    return 0;
}