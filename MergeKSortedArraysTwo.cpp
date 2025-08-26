#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val, arrIdx, eleIdx;
    bool operator>(const Node &other) const{
        return val>other.val;
    }
};

vector<int> mergeKArrays(vector<vector<int>> &arr, int k){
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    vector<int> result;

    for(int i=0; i<k; i++){
        minHeap.push({arr[i][0], i, 0});
    }
    while(!minHeap.empty()){
        Node cur=minHeap.top();
        minHeap.pop();
        result.push_back(cur.val);
        if(cur.eleIdx+1<k){
            minHeap.push({arr[cur.arrIdx][cur.eleIdx], cur.arrIdx, cur.eleIdx+1});
        }
    }
    return result; 
}

int main() {
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 3;
    vector<int> ans = mergeKArrays(arr, k);
    for (int x : ans) cout << x << " ";
}
