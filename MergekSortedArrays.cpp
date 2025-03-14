/*Given k sorted arrays arranged in the form of a matrix of size k * k. 
The task is to merge them into one sorted array. 
Return the merged sorted array 
( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pi;

vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k){
    priority_queue<pi, vector<pi>, greater<pi>> minHeap;

    vector<int> result;

    for(int i=0; i<k; i++){
        minHeap.push({arr[i][0], {i, 0}});
    }

    while(!minHeap.empty()){
        auto top=minHeap.top();
        minHeap.pop();
        int value=top.first;
        int row=top.second.first;
        int col=top.second.second;

        result.push_back(value);
        if(col+1<k){
            minHeap.push({arr[row][col+1], {row, col+1}});
        }
    }
    return result;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = arr.size();
    vector<int> mergedArray = mergeKSortedArrays(arr, k);

    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}