/*Given a binary array nums and an integer k,
 return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, maxLen = 0, zeroCount = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++; // Count 0s in the window

        while (zeroCount > k) { // If there are more than k zeroes, shrink window
            if (nums[left] == 0) zeroCount--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1); // Update max length
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << "Longest Consecutive Ones: " << longestOnes(nums, k) << endl;
    return 0;
}
