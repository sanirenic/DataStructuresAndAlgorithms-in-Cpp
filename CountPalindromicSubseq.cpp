#include <iostream>
#include <vector>
using namespace std;

int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every single character is a palindrome
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    // Build up for lengths from 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s = "aab";
    cout << countPalindromicSubsequences(s) << endl;
}
