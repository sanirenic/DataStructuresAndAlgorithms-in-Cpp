#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    string result = "";
    int start = 0, balance = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') balance++;
        else balance--;

        if (balance == 0) {
            // Remove the outermost parentheses
            result += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }

    return result;
}

int main() {
    string s1 = "((()))";
    string s2 = "()(()())(())";

    cout << "Input: " << s1 << "\nOutput: " << removeOuterParentheses(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << removeOuterParentheses(s2) << "\n";

    return 0;
}
