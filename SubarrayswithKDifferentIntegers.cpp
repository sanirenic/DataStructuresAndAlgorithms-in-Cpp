/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 */

#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(vector<int> & nums, int k){
    if(k==0) return 0;

    unordered_map<int, int> freq;
    int left=0, count=0;

    for(int right=0; right<nums.size(); right++){
        if(++freq[nums[right]]==1)
        k--;

    while(k<0){
        if(--freq[nums[left]==0])
        k++;
        left++;
    }    
    count+=right-left+1;

    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k){
    return atMostKDistinct(nums, k)-atMostKDistinct(nums, k-1);
}


int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k) << endl; 
    return 0;
} 
