
#include <bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &Matrix){
    int m=Matrix.size();
    int n=Matrix[0].size();

    bool firstRowZero=false, firstColZero=false;

    for(int i=0; i<m; i++)
    if(Matrix[i][0]==0) firstRowZero=true;

    for(int j=0; j<n; j++)
    if(Matrix[0][j]==0) firstColZero=true;

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(Matrix[i][j]==0){
                Matrix[i][0]=0;
                Matrix[0][j]=0;
            }
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(Matrix[i][0]==0 || Matrix[0][j]==0){
                Matrix[i][j]==0;
            }
        }
    }
    if(firstRowZero){
        for(int i=0; i<m; i++) Matrix[i][0]=0;

    }
    if(firstColZero){
        for(int j=0; j<n; j++) Matrix[0][j]=0;
    }
}

int main() {
    vector<vector<int>> Matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
     setMatrixZero(Matrix);

     for (auto &row : Matrix) {
         for (int val : row) cout << val << " ";
         cout << "\n";
     }
 }