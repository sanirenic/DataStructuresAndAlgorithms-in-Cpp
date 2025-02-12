/*Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/

#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& nums, int k){
    if(k<0) return 0;

    int left=0, count=0, oddCount=0;

    for(int right=0; right<nums.size(); right++){
        if(nums[right]%2==1) k--;
        while(k<0){
            if(nums[left]%2==1) k++;
            left++;
        }
        count+=(right-left+1);
    }
    return count;
}

int countNiceSubarrays(vector<int> & nums, int k){
    return atMostK(nums, k) - atMostK(nums, k-1);
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << "Number of Nice Subarrays: " << countNiceSubarrays(nums, k) << endl;
    return 0;
}
