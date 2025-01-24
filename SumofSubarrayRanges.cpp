/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long subArrayRanges(vector<int>& nums){
    int n=nums.size();
    long long sum=0;

    vector<int> nextGreater(n, n), prevGreater(n, -1);
    stack<int>st;

    for(int i=0; i<n; ++i){
        while(!st.empty() && nums[st.top()]<nums[i]){
            nextGreater[st.top()]=i;
            st.pop();
        }
        prevGreater[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    for(int i=0; i<n; ++i){
        long long left=i-prevGreater[i];
        long long right=nextGreater[i]-i;
        sum+=nums[i]*left*right;
    }
    vector<int>nextSmaller(n, n), prevSmaller(n, -1);
    while(!st.empty()) st.pop();

    for(int i=0; i<n; ++i){
        while(!st.empty() && nums[st.top()]>nums[i]){
            nextSmaller[st.top()]=i;
            st.pop();
        }
        prevSmaller[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    for(int i=0; i<n; ++i){
        long long left=i-prevSmaller[i];
        long long right=nextSmaller[i]-i;
        sum-=nums[i]*left*right;
    }
    return sum;
}
int main() {
    vector<int> nums = {4, -2, -3, 4, 1};
    cout << subArrayRanges(nums) << endl; // Output: 59
    return 0;
}
