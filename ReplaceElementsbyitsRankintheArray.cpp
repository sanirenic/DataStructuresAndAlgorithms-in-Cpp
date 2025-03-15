/*Replace elements by its rank in the array

Replace elements by its rank in the array

Problem Statement: Given an array of N integers, 
the task is to replace each element of the array by its rank in the array.*/


#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int>& arr){
    int n=arr.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for(int i=0; i<n; i++){
        minHeap.push({arr[i], i});
    }
    vector<int> result(n);
    int rank=1;
    int prevValue=-1;

    while(!minHeap.empty()){
        auto top=minHeap.top();
        minHeap.pop();

        if(top.first!=prevValue){
            prevValue=top.first;
            result[top.second]=rank++;
        }
        else{
            result[top.second]=rank-1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    vector<int> rankedArr = replaceWithRank(arr);

    for (int num : rankedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}