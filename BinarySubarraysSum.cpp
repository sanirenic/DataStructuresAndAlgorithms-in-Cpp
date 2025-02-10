/*Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.*/


#include <iostream>
#include <vector>

using namespace std;

int atMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int left = 0, sum = 0, count = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum > goal) {
            sum -= nums[left++];
        }
        count += (right - left + 1);
    }
    
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
