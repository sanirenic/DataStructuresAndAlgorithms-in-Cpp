#include <bits/stdc++.h>
using namespace std;

string expandFromCenter(string &s, int left, int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);

}

string longestPalindrome(string  s){
    if(s.empty()) return"";
    string res="";
    for(int i=0; i<s.size(); i++){
        string odd=expandFromCenter(s, i, i);
        string even=expandFromCenter(s, i, i+1);
        if(odd.size()>res.size()) res=odd;
        if(even.size()>res.size()) res=even;
    }
    return res;
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
}
