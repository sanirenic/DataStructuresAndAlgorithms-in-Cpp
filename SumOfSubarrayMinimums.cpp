/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 
Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104*/

#include <bits/stdc++.h>
using namespace std;

int sumOfSubarrayMinimums(vector<int> &arr){
    int n=arr.size();
    int mod=10^9+7;

    vector<int>left(n), right(n);
    stack<int>s;

    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
        left[i]=s.empty() ? i+1:i-s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
        right[i]=s.empty()? n-i:s.top()-i;
        s.push(i);
    }
    long long result=0;
    for(int i=0; i<n; i++){
            result=(result+(long long) arr[i]*left[i]*right[i])%mod;
    }
    return result;
}
int main() {
    vector<int> arr = {3, 1, 2, 4};
    cout << sumOfSubarrayMinimums(arr) << endl; // Output: 17
    return 0;
}