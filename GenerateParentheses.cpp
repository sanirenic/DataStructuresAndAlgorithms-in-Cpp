#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string current, int open, int close, int n, vector<string>& result) {
    // Base Case: when current length is 2*n, it's a valid combination
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Recursive Case
    if (open < n)
        backtrack(current + '(', open + 1, close, n, result);

    if (close < open)
        backtrack(current + ')', open, close + 1, n, result);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack("", 0, 0, n, result);
    return result;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (string s : res)
        cout << s << endl;
    return 0;
}
