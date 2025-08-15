#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
    vector<int> prev(n, 1);
    for(int i=1; i<m; i++){
        vector<int> cur(n, 1);

        for(int j=1; j<n; j++){
            cur[j]=cur[j-1]+prev[j];
        }
        prev=cur;
    }
    return prev[n-1];
}

int main() {
    cout << uniquePaths(3, 2) << endl;
}