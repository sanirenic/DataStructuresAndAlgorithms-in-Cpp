#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateZ(string s) {
    int n = s.length();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;

        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

void zSearch(string text, string pattern) {
    string concat = pattern + "$" + text;
    vector<int> Z = calculateZ(concat);
    int patLen = pattern.length();

    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == patLen) {
            cout << i - patLen - 1 << " ";
        }
    }
}

int main() {
    string text = "xyzabxyzabxyz", pattern = "xyz";
    zSearch(text, pattern);
    return 0;
}
