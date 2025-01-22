/*Given an array of N integers and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> monotonicStackApproach (vector<int> &arr, vector<int> &indices){
    int n=arr.size();
    vector<int>countRight(n,0);
    stack<int>s;
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        countRight[i]=s.size();
        s.push(i);
    }
    vector<int>result;
    for(int index:indices){
        result.push_back(countRight[index]);
    }
    return result;
}
int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 5};
    vector<int> result = monotonicStackApproach(arr, indices);

    for (int r : result) {
        cout << r << " ";
    }
    return 0;
}