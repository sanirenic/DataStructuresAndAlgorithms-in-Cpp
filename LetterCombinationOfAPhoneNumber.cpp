#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",     "",     "abc",  "def",  "ghi",
            "jkl",  "mno",  "pqrs", "tuv",  "wxyz"
        };

        vector<string> result;
        string current;

        backtrack(digits, 0, current, result, mapping);
        return result;
    }

    void backtrack(const string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back();  // backtrack step
        }
    }
};

int main() {
    Solution sol;

    vector<string> result1 = sol.letterCombinations("34");
    for (const string& s : result1) cout << s << " ";
    cout << endl;

    vector<string> result2 = sol.letterCombinations("3");
    for (const string& s : result2) cout << s << " ";
    cout << endl;

    return 0;
}
