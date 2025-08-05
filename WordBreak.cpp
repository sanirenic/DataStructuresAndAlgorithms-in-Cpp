#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreakRec(string s, unordered_set<string> &dict) {
    if (s.empty()) return true;

    for (int i = 1; i <= s.size(); i++) {
        string prefix = s.substr(0, i);
        if (dict.count(prefix) && wordBreakRec(s.substr(i), dict)) {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return wordBreakRec(s, dict);
}

int main() {
    string s = "takeuforward";
    vector<string> wordDict = {"take", "forward", "you", "u"};
    cout << (wordBreak(s, wordDict) ? "true" : "false") << endl;
}
