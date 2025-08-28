#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s==t;
}

int main() {
    string s = "anagram", t = "nagaram";
    cout << (isAnagram(s, t) ? "true" : "false") << endl;
}
